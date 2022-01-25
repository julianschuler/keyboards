#!/usr/bin/env python3

import os
import subprocess
import pcbnew
from pcbnew import F_Cu, B_Cu
import dxfgrabber
import numpy as np
from ast import literal_eval
from tempfile import gettempdir


def perp_vec(a):
    """Calculate the vector perpendicular to the given one"""
    return np.array((-a[1], a[0]))


def scale(a, length):
    """Scale a vector to the given legth"""
    norm = np.linalg.norm(a)
    if norm == 0:
        return a
    return a * (length / np.linalg.norm(a))


def line_intersection(a1, a2, b1, b2):
    """Calculate the intersection of lines a and b given by two points each"""
    da = a2 - a1
    db = b2 - b1
    dp = a1 - b1
    da_perp = perp_vec(da)
    denom = np.dot(da_perp, db)
    if denom == 0:
        return None
    return (np.dot(da_perp, dp) / denom.astype(float)) * db + b1


def offset_path(path, offset):
    """Offset a directed path by a given value"""
    off_path = []
    for i, p in enumerate(path):
        q, r = path[max(i - 1, 0)], path[min(i + 1, len(path) - 1)]
        d1 = scale(perp_vec(p - q), offset)
        d2 = scale(perp_vec(r - p), offset)
        if i == 0:
            off_path.append(p + d2)
        elif i == len(path) - 1:
            off_path.append(p + d1)
        off_p = line_intersection(q + d1, p + d1, p + d2, r + d2)
        if off_p is not None:
            off_path.append(off_p)
    return off_path


def to_point(pos):
    """Return a wxPoint at the given position"""
    return pcbnew.wxPointMM(*pos.tolist())


def arc_path(arc_angle, rotation, arc_segments):
    """Calulate the points for path describing an arc with radius 1"""
    a = np.linspace(rotation, arc_angle + rotation, arc_segments * arc_angle // 360)
    a_rad = np.radians(a)
    return np.array(list(zip(np.sin(a_rad), np.cos(a_rad))))


def angled_track_path(start, end):
    """Calculate the points for an angled track path between start and end"""
    diff = end - start
    if abs(diff[0]) > abs(diff[1]):
        d = diff[1] / 2
        dx = d if np.sign(d) == np.sign(diff[0]) else -d
        dy = d
    else:
        d = diff[0] / 2
        dx = d
        dy = d if np.sign(d) == np.sign(diff[1]) else -d
    return start, start + (dx, dy), end - (dx, dy), end


class MatrixPcbGenerator:
    def __init__(self):
        """Constructor of the PCB generator"""
        f_dir = os.path.dirname(__file__)
        self.footprint_path = os.path.join(f_dir, "footprints")
        self.key_footprint_name = "key-switch"
        self.fpc_footprint_name = "fpc-connector"
        self.scad_file = os.path.join(f_dir, "../case/concavum-case.scad")
        self.dxf_file = os.path.join(gettempdir(), "outline-matrix-pcb.dxf")
        self.origin_offset = np.array((195, 90))
        self.fpc_offset = np.array((0, 5.5))
        self.max_rows = 6
        self.max_cols = 6
        self.track_width = 0.15
        self.track_distance = 0.15
        self.arc_segments = 120
        self._track_width_nm = pcbnew.FromMM(self.track_width)
        self.pad_width_min = 4.91

    def generate_board(self, board_template_file):
        """Generate the PCB using the given file as template"""
        # load board from the given template file name
        self.board = pcbnew.LoadBoard(board_template_file)
        # use openscad to generate the PCB outline as DXF file and to get
        # other data as key positions, rotations, etc.
        cmd = (
            "openscad",
            "-D",
            "build_case=false",
            "-o",
            self.dxf_file,
            self.scad_file,
        )
        scad_output = subprocess.check_output(cmd, stderr=subprocess.STDOUT)
        # get PCB parameters from openscad output
        (
            self.pad_size,
            self.cr_off,
            finger_vals,
            thumb_rotation,
            thumb_offset,
            thumb_vals,
            col_conn_vals,
            fpc_indices,
        ) = literal_eval(scad_output.splitlines()[0][6:].decode())
        # set matrix vals
        self.col_count = len(finger_vals)
        self.row_count = len(finger_vals[0])
        self.rows_below = self.cr_off + 1
        self.rows_above = self.row_count - self.rows_below
        # ensure maximum number of rows, columns and thumb keys is not exceeded
        if self.row_count >= self.max_rows or self.col_count > self.max_cols:
            raise ValueError(
                f"Key matrix has {self.col_count} colums and {self.row_count + 1} "
                f"rows. Automatic PCB generation is only supported for key matrices "
                f"with up to {self.max_cols} columns and {self.max_rows} rows "
                f"including the thumb row."
            )
        if len(thumb_vals) > self.max_cols:
            raise ValueError(
                f"Thumb cluster has {len(thumb_vals)} keys. Automatic PCB "
                f"generation is only supported for thumb clusters with up to "
                f"{self.max_cols} keys."
            )
        # import the previously generated DXF as the PCB outline
        self.draw_dxf_lines(self.dxf_file, pcbnew.Edge_Cuts, self.origin_offset)
        # get row and col nets
        nets = self.board.GetNetsByName()
        row_nets = [nets[f"ROW{i+1}"] for i in range(self.max_rows)]
        col_nets = [nets[f"COL{i+1}"] for i in range(self.max_cols)]
        # add keys to the finger cluster
        self.add_finger_cluster(
            finger_vals, row_nets[1:], col_nets, col_conn_vals, fpc_indices
        )
        # add keys to the thumb cluster
        self.add_thumb_cluster(
            thumb_rotation, thumb_offset, thumb_vals, row_nets[0], col_nets
        )
        # add tracks going through the column connectors
        track_counts_top = [
            i + 1 if i < fpc_indices[0] else self.col_count - i - 1
            for i in range(self.col_count)
        ]
        self.add_col_connector_tracks(col_conn_vals, track_counts_top, F_Cu)
        track_counts_bottom = [self.row_count for i in range(self.col_count)]
        self.add_col_connector_tracks(col_conn_vals, track_counts_bottom, B_Cu)
        # add FPC connector and its tracks
        fpc_col = finger_vals[fpc_indices[0]]
        fpc_pos = fpc_col[fpc_indices[1]][:2]
        self.add_fpc_connector(fpc_pos, row_nets, col_nets)
        self.add_row_tracks_fpc_conn(fpc_pos, fpc_col)
        self.add_col_tracks_fpc_conn(fpc_pos, fpc_indices, col_conn_vals)

    def add_finger_cluster(
        self, finger_vals, row_nets, col_nets, col_conn_vals, fpc_indices
    ):
        """Add keys to the finger cluster"""
        off = self.origin_offset
        for i, col in enumerate(finger_vals):
            # if i > 0:
            self.add_col_tracks(col, col_conn_vals, i, fpc_indices)
            for j, pos in enumerate(col):
                ref = f"SW{i+1}{j+1}"
                self.add_key(
                    ref, pos[:2] + off, row_nets[j], col_nets[self.col_count - 1 - i]
                )
                self.add_row_track(col, col_conn_vals, i, j)
                if j > 0:
                    self.add_col_track(pos[:2] + off, col[j - 1][:2] + off, F_Cu)

    def add_thumb_cluster(self, t_rot, t_off, thumb_vals, row_net, col_nets):
        """Add keys to the thumb cluster"""
        t_rot_rad = np.radians(t_rot)
        t_sin, t_cos = np.sin(t_rot_rad), np.cos(t_rot_rad)
        for i, t_pos in enumerate(thumb_vals):
            pos = np.array(
                (
                    t_sin * t_pos[1] + t_off[0] + self.origin_offset[0],
                    t_cos * t_pos[1] - t_off[1] + self.origin_offset[1],
                )
            )
            col = len(thumb_vals) - 1 - i
            self.add_key(f"SW{i+1}", pos, row_net, col_nets[col], t_rot + 180)
            if i > 0:
                self.add_thumb_row_track(
                    np.array(t_pos[:2]),
                    np.array(thumb_vals[i - 1][:2]),
                    pos,
                    F_Cu,
                    t_rot + 180,
                )

    def draw_dxf_lines(self, dxf_file, layer, off=np.zeros(2)):
        """Draw lines from a given DXF file to a specific layer"""
        dxf = dxfgrabber.readfile(dxf_file)
        for e in dxf.entities:
            if e.dxftype == "LINE":
                start = np.array((off[0] + e.start[0], off[1] - e.start[1]))
                end = np.array((off[0] + e.end[0], off[1] - e.end[1]))
                self.draw_line(start, end, layer)

    def draw_line(self, start, end, layer):
        """Draw a line to the given layer specified by its start and end point"""
        seg = pcbnew.PCB_SHAPE(self.board)
        seg.SetLayer(layer)
        seg.SetShape(pcbnew.S_SEGMENT)
        seg.SetStart(to_point(start))
        seg.SetEnd(to_point(end))
        self.board.Add(seg)

    def add_key(self, ref, pos, row_net, col_net, rotation=0):
        """Add a single key to a given (x, y) position"""
        key = pcbnew.FootprintLoad(self.footprint_path, self.key_footprint_name)
        pads = key.Pads()
        pads[1].SetNet(row_net)
        pads[2].SetNet(col_net)
        pads[3].SetNet(col_net)
        key.SetReference(ref)
        key.Rotate(pcbnew.wxPoint(0, 0), rotation * 10)
        key.SetPosition(to_point(pos))
        self.board.Add(key)
        self.add_key_tracks(pos, F_Cu, rotation)

    def add_key_tracks(self, key_pos, layer, rotation):
        """Add tracks within each key"""
        paths = (
            (
                (-2.54, -5.08),
                (-3.81, -2.54),
            ),
            (
                (2.54, -5.08),
                (3.81, -2.54),
                (3.81, 0.04),
                (1.65, 2.2),
                (1.65, 3.41),
            ),
        )
        for path in paths:
            self.add_track_path(path, key_pos, layer, rotation)

    def add_col_track(self, pos, ppos, layer):
        """Add a track connecting the column pins of two keys"""
        diff = ppos - pos
        py = self.pad_size[1] / 2
        dx = self.pad_width_min
        path = np.concatenate(
            (
                ((-3.81, -2.54),),
                angled_track_path(
                    np.array((-3.81, 4.31)),
                    np.array((-dx + max(0, diff[0]), py)),
                ),
                angled_track_path(
                    np.array((-dx + max(0, diff[0]), -py + diff[1])),
                    np.array((-2.54, -5.08)) + diff,
                ),
            )
        )
        self.add_track_path(path, pos, layer)

    def add_col_tracks(self, col, col_conn_vals, i, fpc_indices):
        """Add tracks between a column and its neighbouring column connector"""
        d = self.track_width + self.track_distance
        py = self.pad_size[1] / 2
        key_pos = col[self.cr_off]
        right_side = i < fpc_indices[0]
        pos1, pos2 = None, None
        if i < len(col_conn_vals):
            left1, pos1a, pos1b = col_conn_vals[i]
            pos1 = np.array(pos1a if left1 == 0 else pos1b)
        if i > 0:
            left2, pos2a, pos2b = col_conn_vals[i - 1]
            pos2 = np.array(pos2b if left2 == 0 else pos2a)
        if i == fpc_indices[0]:
            return
        if right_side:
            pos = pos1
            dx = pos[0] + i * d
            dy = pos[1] - d * i / 2
            lower = dy > key_pos[1]
            tx = key_pos[0] - (self.pad_width_min if lower else 3.81)
            ty = key_pos[1] + py if lower else max(dy, key_pos[1] - 2.54)
            t1 = tx
        else:
            pos = pos2
            dx = pos[0] - (self.col_count - i - 1) * d
            dy = pos[1] - d * (self.col_count - 1 - i) / 2
            tx = 2 * (key_pos[0] + self.pad_width_min + d) - dx
            ty = key_pos[1] + 4.31
            t1 = key_pos[0] - 3.81
        path = np.concatenate(
            (
                ((pos[0], dy),),
                angled_track_path(np.array((dx, dy)), np.array((tx, ty))),
                ((t1, ty),),
            )
        )
        self.add_track_path(path, self.origin_offset, F_Cu)
        if pos1 is not None and pos2 is not None:
            lower_key = np.array(col[0][:2])
            num = i if right_side else self.col_count - 1 - i
            y_off1 = (num + (0 if right_side else 1)) / 2 * d
            y_off2 = (num + (1 if right_side else 0)) / 2 * d
            tx = self.pad_width_min + d
            c = self.pad_size[0] / 2 - tx - d - (num - 1) * d * np.sin(np.pi / 8)
            conn_path = (
                pos1 - (0, y_off1),
                np.array((lower_key[0] - tx - c, pos1[1] - y_off1)),
                np.array((lower_key[0] - tx, pos1[1] - y_off1 + c)),
                lower_key + (-tx, 6.7 - tx),
                lower_key + (-2.4, 4.3),
                lower_key + (2.4, 4.3),
                lower_key + (tx, 6.7 - tx),
                np.array((lower_key[0] + tx, pos2[1] - y_off2 + c)),
                np.array((lower_key[0] + tx + c, pos2[1] - y_off2)),
                pos2 - (0, y_off2),
            )
            for j in range(num):
                off_path = offset_path(conn_path, (j + 1) * d)
                self.add_track_path(off_path, self.origin_offset, F_Cu)

    def add_col_tracks_fpc_conn(self, fpc_pos, fpc_indices, col_conn_vals):
        """Add tracks connecting the FPC connector pads with the columns"""
        off = self.origin_offset
        fpc_off = fpc_pos + self.fpc_offset
        cols_left = self.col_count - fpc_indices[0] - 1
        px = self.pad_size[0] / 2
        d = self.track_width + self.track_distance
        for i in range(self.row_count + 1):
            if i < cols_left:
                left, pos1, pos2 = col_conn_vals[fpc_indices[0]]
                pos = np.array(pos1 if left == 0 else pos2)
                tx = self.pad_width_min + (cols_left - i) * d
                dx = self.max_cols - i - 0.5
                ty = abs(tx - dx)
                pos_y = (cols_left - 1) * d / 2
                c = px - self.pad_width_min - (cols_left + 1) * d
                off_path = (
                    (0, pos_y) + pos,
                    (d, pos_y) + pos,
                    (d + c, pos_y + c) + pos,
                    (d + c, pos_y + c + d) + pos,
                )
                path = np.concatenate(
                    (
                        offset_path(off_path, -i * d),
                        (
                            (-tx, -0.6 - ty) + fpc_off,
                            (-dx, -0.6) + fpc_off,
                            (-dx, 0) + fpc_off,
                        ),
                    )
                )
                self.add_track_path(path, off, F_Cu)
            elif i == cols_left:
                path = (
                    (-3.81, -2.54) - self.fpc_offset,
                    (-3.81, -0.6 - abs(i - 4.31)),
                    (-i + 0.5, -0.6),
                    (-i + 0.5, 0),
                )
                self.add_track_path(path, fpc_pos + self.fpc_offset + off, F_Cu)
            else:
                pass

    def add_row_track(self, col, col_conn_vals, i, j):
        """Add a track connecting the row pin of a key with its neighbour's one"""
        if i < len(col_conn_vals):
            self.add_row_track_half(col, col_conn_vals[i], i, j, True)
        if i > 0:
            self.add_row_track_half(col, col_conn_vals[i - 1], i, j, False)

    def add_row_track_half(self, col, col_conn_val, i, j, left_half):
        """Helper function for adding half of a row track"""
        px = self.pad_size[0] / 2
        py = self.pad_size[1] / 2
        d = self.track_width + self.track_distance
        key_pos = np.array(col[j][:2])
        left, pos1, pos2 = col_conn_val
        pos = pos1 if (left == 0) == left_half else pos2
        below = (key_pos - pos)[1] >= 0
        # offset values
        diff_off = (self.row_count - 1) * d / 2
        diff = pos - key_pos + (0, (diff_off if below else -diff_off))
        dr = d * (self.rows_below if below else self.rows_above)
        tx = -self.pad_width_min - dr
        ty = py - d
        t1 = px + tx
        t2 = diff[1] + (self.row_count - 1 - j) * d
        t3 = max(-1.905, t2) if below else min(py, t2)
        c = t1 - self.track_distance
        # calculate extra points for the left- and rightmost column
        extra_points = []
        if i == 0 or i == self.col_count - 1:
            extra_points = self.extra_row_points(
                j, left_half, below, key_pos, col, tx, ty, c
            )
        if extra_points == []:
            extra_points = np.array([]).reshape((0, 2))
        # calculate the first path section of the track
        path = np.concatenate(
            (
                (
                    diff,
                    np.array((t1 - c if left_half else -t1 + c, 0)) + diff,
                    np.array((t1 if left_half else -t1, c if below else -c)) + diff,
                ),
                extra_points,
                ((tx if left_half else -tx, t3),),
            ),
        )
        dn = -d * j if below else d * (self.row_count - j - 1)
        if t2 == t3:
            path = path[:3]
        off_path = offset_path(path, dn if left_half else -dn)
        conn_path = self.row_conn_path(left_half, below, t2 == t3, off_path[-1])
        total_path = np.concatenate((off_path, conn_path))
        self.add_track_path(total_path, key_pos + self.origin_offset, B_Cu)

    def extra_row_points(self, j, left_half, below, key_pos, col, tx, ty, c):
        """Calculate the extra row points for the outermost columns"""
        extra_points = []
        extra_range = col[j : self.cr_off + 1] if below else col[self.cr_off : j + 1]
        extra_pos = [c_pos[:2] - key_pos for c_pos in extra_range]
        for k, r_pos in enumerate(extra_pos[:-1]):
            off1 = extra_pos[k + 1] if below else r_pos
            off2 = r_pos if below else extra_pos[k + 1]
            points = (
                (tx if left_half else -tx, ty - c if below else -ty + c) + off1,
                (tx + c if left_half else -tx - c, ty if below else -ty) + off1,
                (
                    (tx - c if left_half else -tx + c) + off2[0],
                    (ty if below else -ty) + off1[1],
                ),
                (
                    (tx if left_half else -tx) + off2[0],
                    (ty + c if below else -ty - c) + off1[1],
                ),
            )
            extra_points.extend(points)
        return extra_points

    def row_conn_path(self, left_half, below, short, off_path_end):
        """Calculate the diode connecting path section of the row connector"""
        return np.concatenate(
            (
                angled_track_path(
                    off_path_end,
                    np.array(
                        (
                            -1.65 if left_half or not below else 1.65,
                            2.2 if below else 4.3 if short else 5.5,
                        )
                    ),
                ),
                (
                    (-1.65, 2.2) if not left_half and below else (-1.65, 3.41),
                    (-1.65, 3.41),
                ),
            )
        )

    def add_row_tracks_fpc_conn(self, fpc_pos, col):
        """Add all tracks connecting the FPC connector pads with the rows"""
        off = self.origin_offset
        for i in range(-1, self.row_count):
            # the first row is always connected to the thumb cluster
            if i == -1:
                pass
            # the second row is always at a fixed offset to the FPC connector
            elif i == 0:
                path = (
                    (1.5, 0),
                    (1.5, -0.6),
                    (0, -2.1),
                    (0, 2.2) - self.fpc_offset,
                )
                self.add_track_path(path, fpc_pos + self.fpc_offset + off, B_Cu)
            # calculate all other paths dynamically
            else:
                pos = np.array(col[i][:2])
                diff = fpc_pos + self.fpc_offset - pos
                d = self.track_width + self.track_distance
                tx = self.pad_width_min + i * d
                dx = i + 1.5
                ty = abs(tx - dx)
                path = np.concatenate(
                    (
                        (
                            (dx, 0) + diff,
                            (dx, -0.6) + diff,
                            (tx, -0.6 - ty) + diff,
                        ),
                        angled_track_path(
                            np.array((tx, self.pad_size[1] / 2)),
                            np.array((-1.65, 4.3)),
                        ),
                        ((-1.65, 3.41),),
                    )
                )
                self.add_track_path(path, pos + off, F_Cu)

    def add_thumb_row_track(self, pos, ppos, offset, layer, rotation):
        """Add a track connecting the row pins of two thumb pins"""
        diff = ppos - pos
        path = (
            (-1.65, 3.41) - diff,
            (-2.305, 3.41) - diff,
            (-5.715, 0) - diff,
            (-5.715, 6.82),
            (-2.305, 3.41),
            (-1.65, 3.41),
        )
        self.add_track_path(path, offset, layer, rotation)

    def add_col_connector_tracks(self, col_conn_vals, track_count, layer):
        """Add tracks going through the column connectors"""
        off = self.origin_offset
        arc1 = arc_path(90, 0, self.arc_segments)
        arc2 = arc_path(90, 90, self.arc_segments)
        d = self.track_width + self.track_distance
        for i, (c_type, pos1, pos2) in enumerate(col_conn_vals):
            if c_type == -2:
                b = (track_count[i] - 1) * d / 2
                for j in range(track_count[i]):
                    c = j * d - b
                    self.add_track(pos1 + off + (0, c), pos2 + off + (0, c), layer)
            else:
                r = (pos2[0] - pos1[0]) / 2
                a_r = abs(r)
                ln = abs(pos1[1] - pos2[1]) - 2 * a_r
                arc = arc1 if c_type == 0 else arc2
                b = (track_count[i] - 1) * d / 2
                for j in range(track_count[i]):
                    c = j * d - b + r
                    self.add_track_path(arc * c, pos1 + off + (0, a_r), layer)
                    self.add_track(
                        pos1 + off + (c, a_r), pos1 + off + (c, a_r + ln), layer
                    )
                    self.add_track_path(arc * -c, pos2 + off - (0, a_r), layer)

    def add_track_path(self, path, offset, layer, rotation=0):
        """Add a sequence of tracks defining a path"""
        if rotation != 0:
            s, c = np.sin(np.radians(rotation)), np.cos(np.radians(rotation))
            r = np.array(((c, s), (-s, c)))
        else:
            r = np.array(((1, 0), (0, 1)))
        for start, end in zip(path, path[1:]):
            start_pos = r.dot(start) + offset
            end_pos = r.dot(end) + offset
            self.add_track(start_pos, end_pos, layer)

    def add_track(self, start, end, layer):
        """Add a single pcb track"""
        track = pcbnew.PCB_TRACK(self.board)
        track.SetStart(to_point(start))
        track.SetEnd(to_point(end))
        track.SetLayer(layer)
        track.SetWidth(self._track_width_nm)
        self.board.Add(track)

    def add_fpc_connector(self, fpc_pos, row_nets, col_nets):
        """Add the FPC connector"""
        off = self.origin_offset + self.fpc_offset
        fpc = pcbnew.FootprintLoad(self.footprint_path, self.fpc_footprint_name)
        pads = fpc.Pads()
        for i, pad in enumerate(pads):
            if i in range(self.max_cols):
                pad.SetNet(col_nets[i])
            elif i - self.max_cols in range(self.max_rows):
                pad.SetNet(row_nets[i - self.max_cols])
        fpc.SetPosition(to_point(fpc_pos + off))
        self.board.Add(fpc)

    def save_board(self, board_file):
        """Save the board to the given output file"""
        pcbnew.SaveBoard(board_file, self.board)


if __name__ == "__main__":
    f_dir = os.path.dirname(__file__)
    output_dir = os.path.join(f_dir, "matrix-pcb")
    # create output directory if doesn't exist already
    if not os.path.isdir(output_dir):
        os.mkdir(output_dir)
    # generate board from template file and save it to the output directory
    generator = MatrixPcbGenerator()
    generator.generate_board(os.path.join(f_dir, "template-matrix-pcb.kicad_pcb"))
    generator.save_board(os.path.join(output_dir, "matrix-pcb.kicad_pcb"))
