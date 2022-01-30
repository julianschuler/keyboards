#!/usr/bin/env python3

import os
import subprocess
from ast import literal_eval
from tempfile import gettempdir
import dxfgrabber
import numpy as np
import pcbnew
from pcbnew import F_Cu, B_Cu
from kikit.units import mm
from kikit.substrate import roundPoint
from kikit.panelize import Panel, TabAnnotation, Origin, buildTabs, getOriginCoord
from kikit.panelize_ui_impl import dummyFramingSubstrate


def perp_vec(a):
    """Calculate the vector perpendicular to the given one"""
    return np.array((-a[1], a[0]))


def scale(a, length):
    """Scale a vector to the given length"""
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


def opposite_layer(layer):
    """Return the layer opposite to the given one"""
    return F_Cu if layer is B_Cu else B_Cu


class MatrixPcbGenerator:
    def __init__(self):
        """Constructor of the PCB generator"""
        f_dir = os.path.dirname(__file__)
        self.footprint_path = os.path.join(f_dir, "footprints")
        self.key_footprint_name = "key-switch"
        self.fpc_footprint_name = "fpc-connector"
        self.scad_file = os.path.join(f_dir, "../case/concavum-case.scad")
        self.dxf_file = os.path.join(gettempdir(), "outline-matrix-pcb.dxf")
        self.drc_file = os.path.join(gettempdir(), "drc-report.txt")
        self.origin_offset = np.array((195, 90))
        self.fpc_offset = np.array((0, 5.5))
        self.max_rows = 6
        self.max_cols = 6
        self.track_width = 0.13
        self.track_clearance = 0.13
        self.via_diameter = 0.6
        self.via_hole = 0.3
        self.arc_segments = 120
        self.pad_width_min = 4.91
        self._track_width_nm = pcbnew.FromMM(self.track_width)
        self._via_diameter_nm = pcbnew.FromMM(self.via_diameter)
        self._via_hole_nm = pcbnew.FromMM(self.via_hole)

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
            t_rot,
            t_off,
            t_vals,
            t_conn_vals,
            col_conn_vals,
            fpc_index,
            t_index,
        ) = literal_eval(scad_output.splitlines()[0][6:].decode())
        # set matrix vals
        self.col_count = len(finger_vals)
        self.row_count = len(finger_vals[0])
        self.t_col_count = len(t_vals)
        self.rows_below = self.cr_off + 1
        self.rows_above = self.row_count - self.rows_below
        # ensure maximum number of rows, columns and thumb keys is not exceeded
        if self.row_count >= self.max_rows or self.col_count > self.max_cols:
            raise ValueError(
                f"Key matrix has {self.col_count} columns and {self.row_count + 1} "
                f"rows. Automatic PCB generation is only supported for key matrices "
                f"with up to {self.max_cols} columns and {self.max_rows} rows "
                f"including the thumb row."
            )
        if self.t_col_count > self.max_cols:
            raise ValueError(
                f"Thumb cluster has {self.t_col_count} keys. Automatic PCB "
                f"generation is only supported for thumb clusters with up to "
                f"{self.max_cols} keys."
            )
        # ensure FPC index is between 1 and 2
        if fpc_index not in range(1, 3):
            raise ValueError(
                f"The FPC index has a value of {fpc_index}. Automatic PCB "
                f"generation is only supported for FPC indices between 1 and 2. "
                f"Adjust the variable finger_anchor_index in the SCAD file "
                f"accordingly."
            )
        # calculate tab positions for panelization
        self.tab_positions = self.calculate_tab_positions(
            finger_vals, t_rot, t_off, t_vals, fpc_index
        )
        # import the previously generated DXF as the PCB outline
        self.draw_dxf_lines(self.dxf_file, pcbnew.Edge_Cuts, self.origin_offset)
        # get row and col nets
        nets = self.board.GetNetsByName()
        # for net in nets.values():
        #     net.SetNetClass(self.netclass)
        row_nets = [nets[f"ROW{i+1}"] for i in range(self.max_rows)]
        col_nets = [nets[f"COL{i+1}"] for i in range(self.max_cols)]
        # add keys to the finger cluster
        self.add_finger_cluster(
            finger_vals, row_nets[1:], col_nets, col_conn_vals, fpc_index
        )
        # add keys to the thumb cluster
        self.add_thumb_cluster(
            t_rot, t_off, t_vals, row_nets[0], col_nets, t_index, t_conn_vals[14]
        )
        # add tracks going through the column connectors
        track_counts_top = [
            i + 1 if i < fpc_index else self.col_count - i - 1
            for i in range(self.col_count)
        ]
        self.add_col_connector_tracks(col_conn_vals, track_counts_top, F_Cu)
        track_counts_bottom = [self.row_count for i in range(self.col_count)]
        self.add_col_connector_tracks(col_conn_vals, track_counts_bottom, B_Cu)
        # add tracks going through the thumb connector
        self.add_thumb_connector_tracks(t_conn_vals, 1, F_Cu)
        self.add_thumb_connector_tracks(t_conn_vals, self.t_col_count, B_Cu)
        # add FPC connector and its tracks
        fpc_col = finger_vals[fpc_index]
        fpc_pos = fpc_col[0][:2]
        f_pos = t_conn_vals[12]
        self.add_fpc_connector(fpc_pos, row_nets, col_nets)
        self.add_row_tracks_fpc_conn(fpc_pos, fpc_col, F_Cu)
        self.add_col_tracks_fpc_conn(fpc_pos, fpc_index, col_conn_vals, F_Cu)
        self.add_thumb_tracks_fpc_conn(fpc_pos, f_pos, 1, F_Cu)
        self.add_thumb_tracks_fpc_conn(fpc_pos, f_pos, self.t_col_count, B_Cu)

    def add_finger_cluster(
        self, finger_vals, row_nets, col_nets, col_conn_vals, fpc_index
    ):
        """Add keys to the finger cluster"""
        off = self.origin_offset
        for i, col in enumerate(finger_vals):
            self.add_col_tracks(col, col_conn_vals, i, fpc_index, F_Cu)
            col_net = col_nets[
                (self.max_cols if i <= fpc_index else self.col_count) - 1 - i
            ]
            for j, pos in enumerate(col):
                ref = f"SW{i+1}{j+1}"
                self.add_key(ref, pos[:2] + off, row_nets[j], col_net)
                self.add_row_track(col, col_conn_vals, i, j, B_Cu)
                if j > 0:
                    self.add_col_track(pos[:2] + off, col[j - 1][:2] + off, F_Cu)

    def add_thumb_cluster(
        self, t_rot, t_off, t_vals, row_net, col_nets, t_index, t_conn_pos
    ):
        """Add keys to the thumb cluster"""
        a = t_rot + 180
        t_rot_rad = np.radians(a)
        t_sin, t_cos = np.sin(t_rot_rad), np.cos(t_rot_rad)
        for i, t_pos in enumerate(t_vals):
            pos = np.array(
                (
                    t_sin * t_pos[1] + t_off[0] + self.origin_offset[0],
                    t_cos * t_pos[1] - t_off[1] + self.origin_offset[1],
                )
            )
            col = self.max_cols - 1 - i
            self.add_key(f"SW{i+1}", pos, row_net, col_nets[col], a)
            self.add_thumb_col_track(i, a, t_vals, t_index, t_conn_pos, B_Cu)
            if i > 0:
                self.add_thumb_row_track(
                    np.array(t_pos[:2]), np.array(t_vals[i - 1][:2]), pos, F_Cu, a
                )
            if i == t_index:
                self.add_thumb_row_conn_track(pos, a, F_Cu)

    def draw_dxf_lines(self, dxf_file, layer, off=np.zeros(2)):
        """Draw lines from a given DXF file to a specific layer"""
        dxf = dxfgrabber.readfile(dxf_file)
        for e in dxf.entities:
            if e.dxftype == "LINE":
                start = pcbnew.wxPoint(
                    *roundPoint(
                        to_point(np.array((off[0] + e.start[0], off[1] - e.start[1])))
                    )
                )
                end = pcbnew.wxPoint(
                    *roundPoint(
                        to_point(np.array((off[0] + e.end[0], off[1] - e.end[1])))
                    )
                )
                self.draw_line(start, end, layer)

    def draw_line(self, start, end, layer):
        """Draw a line to the given layer specified by its start and end point"""
        if start == end:
            return
        seg = pcbnew.PCB_SHAPE(self.board)
        seg.SetLayer(layer)
        seg.SetShape(pcbnew.S_SEGMENT)
        seg.SetStart(start)
        seg.SetEnd(end)
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
                (3.81, 0.24),
                (1.65, 2.4),
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

    def add_col_tracks(self, col, col_conn_vals, i, fpc_index, layer):
        """Add tracks between a column and its neighbouring column connector"""
        d = self.track_width + self.track_clearance
        px = self.pad_size[0] / 2
        py = self.pad_size[1] / 2
        key_pos = col[self.cr_off]
        right_side = i < fpc_index
        pos1, pos2 = None, None
        if i < len(col_conn_vals):
            c_type1, pos1a, pos1b = col_conn_vals[i]
            pos1 = np.array(pos1a if c_type1 == 0 else pos1b)
        if i > 0:
            c_type2, pos2a, pos2b = col_conn_vals[i - 1]
            pos2 = np.array(pos2b if c_type2 == 0 else pos2a)
        if i == fpc_index:
            return
        num = i if right_side else self.col_count - 1 - i
        t1 = num * d * np.sin(np.pi / 8) + self.track_clearance * 1.5
        pos = pos1 if right_side else pos2
        dx = pos[0] + (t1 if right_side else -t1)
        dy = pos[1] - d * num / 2
        if right_side:
            lower = dy > key_pos[1]
            tx = key_pos[0] - (self.pad_width_min if lower else 3.81)
            t2 = tx
            t3 = key_pos[1] + py if lower else max(dy, key_pos[1] - 2.54)
            ty = min(t3, dy + key_pos[0] - 3.81 - dx)
        else:
            tx = 2 * (key_pos[0] + self.pad_width_min + d) - dx
            ty = key_pos[1] + 4.31
            t2 = key_pos[0] - 3.81
            t3 = ty
        path = np.concatenate(
            (
                ((pos[0], dy),),
                angled_track_path(np.array((dx, dy)), np.array((tx, ty))),
                ((t2, t3),),
            )
        )
        self.add_track_path(path, self.origin_offset, layer)
        if pos1 is not None and pos2 is not None:
            lower_key = np.array(col[0][:2])
            y_off1 = (num - (2 if right_side else 1)) / 2 * d
            y_off2 = (num - (1 if right_side else 2)) / 2 * d
            tx = self.pad_width_min + d * 2
            c = px - tx - self.track_clearance - (num - 1) * d * np.sin(np.pi / 8)
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
                off_path = offset_path(conn_path, d * j)
                self.add_track_path(off_path, self.origin_offset, layer)

    def add_col_tracks_fpc_conn(self, fpc_pos, fpc_index, col_conn_vals, layer):
        """Add tracks connecting the FPC connector pads with the columns"""
        off = self.origin_offset
        fpc_off = fpc_pos + self.fpc_offset
        cols_left = self.col_count - fpc_index - 1
        for i in range(self.col_count):
            # add a track for the left column
            if i < cols_left:
                c_type, pos1, pos2 = col_conn_vals[fpc_index]
                pos = np.array(pos1 if c_type == 0 else pos2)
                self.add_left_col_track_fpc_conn(fpc_off, fpc_index, pos, i, layer)
            # add a track for the center column
            elif i == cols_left:
                dy = 2.9 - self.fpc_offset[1] if fpc_index == 1 else -0.6
                path = (
                    (-3.81, -2.54) - self.fpc_offset,
                    (-3.81, dy - abs(self.col_count - i - 5.31)),
                    (i - self.col_count + 1.5, dy),
                    (i - self.col_count + 1.5, 0),
                )
                self.add_track_path(path, fpc_pos + self.fpc_offset + off, layer)
            # add a track for a right column
            else:
                c_type, pos1, pos2 = col_conn_vals[fpc_index - 1]
                pos = np.array(pos2 if c_type == 0 else pos1)
                self.add_right_col_track_fpc_conn(fpc_off, fpc_index, pos, i, layer)

    def add_left_col_track_fpc_conn(self, fpc_off, fpc_index, pos, i, layer):
        """Helper function for adding a track between a left column and FPC pad"""
        off = self.origin_offset
        cols_left = self.col_count - fpc_index - 1
        px = self.pad_size[0] / 2
        d = self.track_width + self.track_clearance
        tx = self.pad_width_min + (cols_left - i) * d
        dx = self.max_cols - i - 1.5
        ty = abs(tx - dx)
        pos_y = (cols_left - 1) * d / 2
        t1 = px - self.pad_width_min - (cols_left) * d
        c = t1 - self.track_clearance
        off_path = (
            (0, pos_y) + pos,
            (t1 - c, pos_y) + pos,
            (t1, pos_y + c) + pos,
            (t1, pos_y + c + d) + pos,
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

    def add_right_col_track_fpc_conn(self, fpc_off, fpc_index, pos, i, layer):
        """Helper function for adding a track between a right column and FPC pad"""
        px = self.pad_size[0] / 2
        d = self.track_width + self.track_clearance
        cols_right = fpc_index
        cols_left = self.col_count - cols_right - 1
        fpc_w = (self.max_cols + self.max_rows) / 2 - 0.5
        pos_y = (cols_right - 1) * d / 2
        t1 = max(
            pos[0] - px + self.pad_width_min + self.row_count * d,
            fpc_off[0] + fpc_w + 0.3 + d,
        )
        t2 = pos[0] - t1 - (cols_right - 1) * d
        c1 = t2 - self.track_clearance
        c2 = t1 - fpc_w - fpc_off[0] - np.tan(np.pi / 8) * (d + 0.3)
        off_path1 = (
            (0, pos_y) + pos,
            (-t2 + c1, pos_y) + pos,
            (-t2, pos_y + c1) + pos,
            (-t2, pos_y + c1 + d) + pos,
        )
        off_path2 = (
            (t1 - fpc_off[0], 0.9 - c2) + fpc_off,
            (t1 - fpc_off[0], 0.9 - c2 + d) + fpc_off,
            (t1 - c2 - fpc_off[0], 0.9 + d) + fpc_off,
            (fpc_w, 0.9 + d) + fpc_off,
        )
        end_pos = (i - self.col_count + 1.5, 0) + fpc_off
        # a via and a track on the opposite layer is needed
        if i == self.col_count - 1 and fpc_index == 2:
            via_pos = (fpc_w - d, 0.9 + (cols_right + 1) * d) + fpc_off
            conn_path = (via_pos,)
            self.add_track_path(
                angled_track_path((0, 0.6) + end_pos, via_pos),
                self.origin_offset,
                opposite_layer(layer),
            )
            self.add_via(via_pos + self.origin_offset)
        # a direct connection is possible
        else:
            conn_path = (
                (0.3 + d, 0.9 + d) + end_pos,
                (0, 0.6) + end_pos,
                end_pos,
            )
        path = np.concatenate(
            (
                offset_path(off_path1, (self.col_count - 1 - i) * d),
                offset_path(off_path2, -(i - cols_left - 1) * d),
                conn_path,
            )
        )
        self.add_track_path(path, self.origin_offset, layer)

    def add_row_track(self, col, col_conn_vals, i, j, layer):
        """Add a track connecting the row pin of a key with its neighbour's one"""
        # add left half
        if i < len(col_conn_vals):
            self.add_row_track_half(col, col_conn_vals[i], i, j, True, layer)
        # add right half
        if i > 0:
            self.add_row_track_half(col, col_conn_vals[i - 1], i, j, False, layer)

    def add_row_track_half(self, col, col_conn_val, i, j, left_half, layer):
        """Helper function for adding half of a row track"""
        px = self.pad_size[0] / 2
        py = self.pad_size[1] / 2
        d = self.track_width + self.track_clearance
        key_pos = np.array(col[j][:2])
        c_type, pos1, pos2 = col_conn_val
        pos = pos1 if (c_type == 0) == left_half else pos2
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
        c = t1 - self.track_clearance
        # calculate extra points for the left- and rightmost column
        extra_points = []
        if c_type == -2 and (i == 0 or i == self.col_count - 1):
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
        self.add_track_path(total_path, key_pos + self.origin_offset, layer)

    def extra_row_points(self, j, left_half, below, key_pos, col, tx, ty, cm):
        """Calculate the extra row points for the outermost columns"""
        extra_points = []
        extra_range = col[j : self.cr_off + 1] if below else col[self.cr_off : j + 1]
        extra_pos = [c_pos[:2] - key_pos for c_pos in extra_range]
        for k, r_pos in enumerate(extra_pos[:-1]):
            off1 = extra_pos[k + 1] if below else r_pos
            off2 = r_pos if below else extra_pos[k + 1]
            c = min(cm, abs(off1[0] - off2[0]) / 2)
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
                            2.4 if below else 4.3 if short else 5.5,
                        )
                    ),
                ),
                (
                    (-1.65, 2.4) if not left_half and below else (-1.65, 3.41),
                    (-1.65, 3.41),
                ),
            )
        )

    def add_row_tracks_fpc_conn(self, fpc_pos, col, layer):
        """Add all tracks connecting the FPC connector pads with the rows"""
        off = self.origin_offset
        for i in range(self.row_count):
            # the second row is always at a fixed offset to the FPC connector
            if i == 0:
                path = (
                    (1.5, 0),
                    (1.5, -0.6),
                    (0, -2.1),
                    (0, 2.4) - self.fpc_offset,
                )
                self.add_track_path(
                    path, fpc_pos + self.fpc_offset + off, opposite_layer(layer)
                )
            # calculate all other paths dynamically
            else:
                pos = np.array(col[i][:2])
                diff = fpc_pos + self.fpc_offset - pos
                d = self.track_width + self.track_clearance
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
                self.add_track_path(path, pos + off, layer)

    def add_thumb_row_track(self, pos, ppos, offset, layer, rotation):
        """Add a track connecting the row pins of two thumb pins"""
        diff = ppos - pos
        path = (
            (-1.65, 3.41),
            (-2.305, 3.41),
            (-5.715, 0),
            (-5.715, 6.82) + diff,
            (-2.305, 3.41) + diff,
            (-1.65, 3.41) + diff,
        )
        self.add_track_path(path, offset, layer, rotation)

    def add_thumb_col_track(self, i, t_rot, t_vals, t_index, t_conn_pos, layer):
        """Add a track connecting the thumb column to the thumb connector"""
        off = self.origin_offset + (t_conn_pos[0], -t_conn_pos[1])
        px = self.pad_size[0] / 2
        py = self.pad_size[1] / 2
        d = self.track_width + self.track_clearance
        # offset values
        below = i > t_index
        dy = (self.t_col_count - 1) * d / 2
        d_off = np.array((0, dy if below else -dy))
        diff = (np.array(t_vals[i]) - np.array(t_vals[t_index]))[:2]
        dr = d * (self.t_col_count - t_index - 2 if below else t_index)
        tx = px - self.pad_width_min - dr
        c = tx - self.track_clearance
        # calculate the first path section of the track
        path = np.concatenate(
            (
                (
                    d_off,
                    (tx - c, 0) + d_off,
                    (tx, c if below else -c) + d_off,
                    (tx, -py if below else py) + diff,
                ),
            ),
        )
        if not below and path[-1][1] > path[-2][1]:
            path = path[:-1]
        off_path = offset_path(
            path, -(self.t_col_count - i - 1) * d if below else d * i
        )
        total_path = np.concatenate(
            (
                off_path,
                angled_track_path(
                    off_path[-1],
                    ((px - 2.54, -5.08) if below else (px - 3.81, -2.54)) + diff,
                ),
            )
        )
        self.add_track_path(total_path, off, layer, t_rot)

    def add_thumb_row_conn_track(self, key_pos, t_rot, layer):
        """Add a track connecting the thumb row to the thumb connector"""
        path = (
            (-1.65, 3.41),
            (-2.305, 3.41),
            (-5.715, 0),
            (-self.pad_size[0] / 2, 0),
        )
        self.add_track_path(path, key_pos, layer, t_rot)

    def add_thumb_tracks_fpc_conn(self, fpc_pos, f_pos, track_count, layer):
        """Add tracks connecting the FPC connector pads with the thumb cluster"""
        pos1 = np.array(fpc_pos[:2]) + self.fpc_offset
        pos2 = np.array((f_pos[0], -f_pos[1]))
        d = self.track_width + self.track_clearance
        for i in range(track_count):
            dx = d * (i - (track_count - 1) / 2)
            tx = i - track_count + 1.5 if track_count > 1 else -self.max_cols + 0.5
            dy = abs(pos1[0] - pos2[0] + tx - dx) + 0.6 + pos1[1]
            ty = min(dy, pos2[1] - i * d)
            path = np.concatenate(
                (
                    ((tx, 0) + pos1,),
                    angled_track_path(
                        (tx, 0.6) + pos1,
                        np.array((pos2[0] + dx, ty)),
                    ),
                    (pos2 + (dx, 0),),
                )
            )
            self.add_track_path(path, self.origin_offset, layer)

    def add_col_connector_tracks(self, col_conn_vals, track_count, layer):
        """Add tracks going through the column connectors"""
        off = self.origin_offset
        arc1 = arc_path(90, 0, self.arc_segments)
        arc2 = arc_path(90, 90, self.arc_segments)
        d = self.track_width + self.track_clearance
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

    def add_thumb_connector_tracks(self, conn_vals, track_count, layer):
        """Add tracks going through the thumb connector"""
        (r, a, _, _, _, _, conn_l, _, _, _, _, _, f_pos, f_arc, t_pos, _) = conn_vals
        off = self.origin_offset
        d = self.track_width + self.track_clearance
        arc1 = arc_path(a, -90, self.arc_segments)
        arc2 = arc_path(90, a, self.arc_segments)
        pos1 = (f_pos[0], -f_pos[1])
        pos2 = (t_pos[0], -t_pos[1])
        a_rad = np.radians(a)
        r_off = np.array((np.sin(a_rad), np.cos(a_rad)))
        for i in range(track_count):
            c = (i - (track_count - 1) / 2) * d
            self.add_track_path(arc1 * (c + r), pos1 + off + (r, 0), layer)
            off_track = offset_path((np.array((0, 0)), np.array((0, conn_l))), c)
            self.add_track_path(off_track, off + (f_arc[0], -f_arc[1]), layer, a)
            self.add_track_path(arc2 * (c + r), pos2 + off - r * r_off, layer)

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
        if (start == end).all():
            return
        track = pcbnew.PCB_TRACK(self.board)
        track.SetStart(to_point(start))
        track.SetEnd(to_point(end))
        track.SetLayer(layer)
        track.SetWidth(self._track_width_nm)
        self.board.Add(track)

    def add_via(self, pos):
        """Add a single via"""
        via = pcbnew.PCB_VIA(self.board)
        via.SetWidth(self._via_diameter_nm)
        via.SetDrill(self._via_hole_nm)
        via.SetPosition(to_point(pos))
        self.board.Add(via)

    def add_fpc_connector(self, fpc_pos, row_nets, col_nets):
        """Add the FPC connector"""
        off = self.origin_offset + self.fpc_offset
        fpc = pcbnew.FootprintLoad(self.footprint_path, self.fpc_footprint_name)
        pads = fpc.Pads()
        pads[0].SetNet(row_nets[0])
        for i, pad in enumerate(pads[1:]):
            if i in range(self.max_cols):
                pad.SetNet(col_nets[i])
            elif i - self.max_cols in range(self.max_rows - 1):
                pad.SetNet(row_nets[i - self.max_cols + 1])
        fpc.SetPosition(to_point(fpc_pos + off))
        fpc.SetReference("U1")
        self.board.Add(fpc)

    def save_board(self, board_file):
        """Save the board to the given output file"""
        pcbnew.SaveBoard(board_file, self.board)

    def calculate_tab_positions(self, finger_vals, t_rot, t_off, t_vals, fpc_index):
        """Calculate the tab positions for the finger cluster"""
        annotations = []
        px = self.pad_size[0] / 2
        py = self.pad_size[1] / 2
        x_off = min(finger_vals[-1][0][0], finger_vals[-1][-1][0]) - px
        max_y = max([col[0][1] for col in finger_vals]) + py
        min_y = min([col[-1][1] for col in finger_vals]) - py
        for i, col in enumerate(finger_vals):
            pos1 = (col[-1][0] - x_off, -1)
            pos2 = (col[0][0] - x_off, max_y - min_y + 1)
            annotations.append((pos1, (0, 1)))
            if i == fpc_index:
                annotations.append(((pos2[0] - 7 + 0.001, pos2[1]), (0, -1)))
            else:
                annotations.append((pos2, (0, -1)))
        return annotations

    def get_tab_positions(self):
        """Return the previously calculated tab positions"""
        return self.tab_positions


class BoardPanelizer:
    def __init__(self):
        self.rail_thickness = 5 * mm
        self.tab_width = 5 * mm
        self.mousebite_drill = 0.5 * mm
        self.mousebite_spacing = 0.75 * mm
        self.frame_offset = (2 * mm, None)
        self.origin_offset = np.array((150, 90))

    def panelize_board(self, board_file, panel_file, tab_positions):
        """Add tabs and break-away panels for manufacturing"""
        # create a panel and add the board to it
        panel = Panel(panel_file)
        bounding_box = panel.appendBoard(
            board_file,
            to_point(self.origin_offset),
            origin=Origin.Center,
            tolerance=1 * mm,
        )
        # calculate partition line from bounding box and a dummy for the frame
        panel.buildPartitionLineFromBB(
            dummyFramingSubstrate(panel.substrates, self.frame_offset)
        )
        # create tabs from given positions
        origin = getOriginCoord(Origin.TopLeft, bounding_box)
        tab_annotations = []
        for pos, dir in tab_positions:
            tab_pos = pcbnew.wxPoint(pos[0] * mm + origin[0], pos[1] * mm + origin[1])
            tab_annotations.append(TabAnnotation(None, tab_pos, dir, self.tab_width))
        substrate = panel.substrates[0]
        tabs, cuts = buildTabs(substrate, substrate.partitionLine, tab_annotations)
        panel.boardSubstrate.union(tabs)
        # create rails to the top and bottom and mouse bites from the cuts
        panel.makeRailsTb(self.rail_thickness)
        panel.makeMouseBites(cuts, self.mousebite_drill, self.mousebite_spacing)
        panel.copperFillNonBoardAreas()
        panel.addMillFillets(1 * mm)
        panel.save()


if __name__ == "__main__":
    f_dir = os.path.dirname(__file__)
    output_dir = os.path.join(f_dir, "matrix-pcb")
    board_file = os.path.join(output_dir, "matrix-pcb.kicad_pcb")
    panel_file = os.path.join(output_dir, "matrix-pcb-panel.kicad_pcb")
    # create output directory if doesn't exist already
    if not os.path.isdir(output_dir):
        os.mkdir(output_dir)
    # generate board from template file and save it to the output directory
    generator = MatrixPcbGenerator()
    generator.generate_board(os.path.join(f_dir, "template-matrix-pcb.kicad_pcb"))
    generator.save_board(board_file)
    tab_positions = generator.get_tab_positions()
    panelizer = BoardPanelizer()
    panelizer.panelize_board(board_file, panel_file, tab_positions)
