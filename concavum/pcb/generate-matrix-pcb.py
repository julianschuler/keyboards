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
        # get key positions and co. from openscad output
        scad_vals = literal_eval(scad_output.splitlines()[0][6:].decode())
        # set matrix vals
        self.pad_size = scad_vals[0]
        self.cr_off = scad_vals[1]
        self.col_count = len(scad_vals[2])
        self.row_count = len(scad_vals[2][0])
        self.rows_below = self.cr_off + 1
        self.rows_above = self.row_count - self.rows_below
        # import the previously generated DXF as the PCB outline
        self.draw_dxf_lines(self.dxf_file, pcbnew.Edge_Cuts, self.origin_offset)
        # get row and col nets
        nets = self.board.GetNetsByName()
        row_nets = [nets[f"ROW{i+1}"] for i in range(self.max_rows)]
        col_nets = [nets[f"COL{i+1}"] for i in range(self.max_cols)]
        # add keys to the finger cluster
        self.add_finger_cluster(scad_vals[2], row_nets[1:], col_nets, scad_vals[6])
        # add keys to the thumb cluster
        self.add_thumb_cluster(
            scad_vals[3], scad_vals[4], scad_vals[5], row_nets[0], col_nets
        )
        # add tracks going through the column connectors
        self.add_col_connector_tracks(scad_vals[6], len(scad_vals[2][0]), B_Cu)
        # add FPC connector
        self.add_fpc_connector(
            scad_vals[2][scad_vals[7][0]][scad_vals[7][1]], row_nets, col_nets
        )

    def add_finger_cluster(self, finger_vals, row_nets, col_nets, col_connector_vals):
        """Add keys to the finger cluster"""
        off = self.origin_offset
        for i, col in enumerate(finger_vals):
            for j, pos in enumerate(col):
                ref = f"SW{i+1}{j+1}"
                self.add_key(ref, pos[:2] + off, row_nets[j], col_nets[i])
                self.add_row_track(col, col_connector_vals, i, j)
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
        seg.SetStart(self.to_point(start))
        seg.SetEnd(self.to_point(end))
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
        key.SetPosition(self.to_point(pos))
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
        path = np.concatenate(
            (
                ((-3.81, -2.54),),
                angled_track_path(
                    np.array((-3.81, 3.175)),
                    np.array((-3.81 + max(0, diff[0]), py)),
                ),
                angled_track_path(
                    np.array((-3.81 + max(0, diff[0]), -py + diff[1])),
                    np.array((-2.54, -5.08)) + diff,
                ),
            )
        )
        self.add_track_path(path, pos, layer)

    def add_row_track(self, col, col_connector_vals, i, j):
        """Add a track connecting the row pin of a key with its neighbour's one"""
        if i < len(col_connector_vals):
            self.add_row_track_half(col, col_connector_vals[i], i, j, True)
        if i > 0:
            self.add_row_track_half(col, col_connector_vals[i - 1], i, j, False)

    def add_row_track_half(self, col, cv, i, j, left_half):
        """Helper function for adding half of a row track"""
        px = self.pad_size[0] / 2
        py = self.pad_size[1] / 2
        d = self.track_width + self.track_distance
        key_pos = np.array(col[j][:2])
        left, pos1, pos2 = cv
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

    def add_col_connector_tracks(self, col_connector_vals, track_count, layer):
        """Add tracks going through the column connectors"""
        off = self.origin_offset
        arc1 = arc_path(90, 0, self.arc_segments)
        arc2 = arc_path(90, 90, self.arc_segments)
        b = (track_count - 1) * (self.track_width + self.track_distance) / 2
        for c_type, pos1, pos2 in col_connector_vals:
            if c_type == -2:
                for d in np.linspace(-b, b, track_count):
                    self.add_track(pos1 + off + (0, d), pos2 + off + (0, d), layer)
            else:
                r = (pos2[0] - pos1[0]) / 2
                a_r = abs(r)
                ln = abs(pos1[1] - pos2[1]) - 2 * a_r
                arc = arc1 if c_type == 0 else arc2
                for d in np.linspace(r - b, r + b, track_count):
                    self.add_track_path(arc * d, pos1 + off + (0, a_r), layer)
                    self.add_track(
                        pos1 + off + (d, a_r), pos1 + off + (d, a_r + ln), layer
                    )
                    self.add_track_path(arc * -d, pos2 + off - (0, a_r), layer)

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
        track.SetStart(self.to_point(start))
        track.SetEnd(self.to_point(end))
        track.SetLayer(layer)
        track.SetWidth(self._track_width_nm)
        self.board.Add(track)

    def add_fpc_connector(self, pos, row_nets, col_nets):
        """Add the FPC connector"""
        off = self.origin_offset + (0, 5.5)
        fpc = pcbnew.FootprintLoad(self.footprint_path, self.fpc_footprint_name)
        pads = fpc.Pads()
        for i, pad in enumerate(pads):
            if i in range(self.max_cols):
                pad.SetNet(col_nets[i])
            elif i - self.max_cols in range(self.max_rows):
                pad.SetNet(row_nets[i - self.max_cols])
        fpc.SetPosition(self.to_point(pos[:2] + off))
        self.board.Add(fpc)

    def save_board(self, board_file):
        """Save the board to the given output file"""
        pcbnew.SaveBoard(board_file, self.board)

    def to_point(self, pos):
        """Return a wxPoint with the given position"""
        return pcbnew.wxPointMM(*pos.tolist())


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
