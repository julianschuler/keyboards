#!/usr/bin/env python3

import os
import subprocess
import pcbnew
import dxfgrabber
import numpy as np
from ast import literal_eval


class GeneratePcb(pcbnew.ActionPlugin):
    def defaults(self):
        """Set name and properties of the Plugin"""
        self.name = "Generate key matrix pcb"
        self.category = "Utils"
        self.description = "Generate the key matrix pcb from the openscad script"
        self.show_toolbar_button = True
        f_dir = os.path.dirname(__file__)
        self.footprint_path = os.path.join(f_dir, "footprints")
        self.footprint_name = "key-switch"
        self.scad_file = os.path.join(f_dir, "../case/concavum-case.scad")
        self.dxf_file = os.path.join(f_dir, "outline-key-matrix.dxf")
        self.origin_offset = np.array((195, 90))
        self.max_rows = 6
        self.max_cols = 8
        self.track_width = pcbnew.FromMM(0.3)
        self.arc_segments = 120

    def Run(self, board_file=None):
        """Method to be called when the plugin is executed"""
        # load board either from file name or get the default
        if board_file is not None:
            self.board = pcbnew.LoadBoard(board_file)
        else:
            self.board = pcbnew.GetBoard()
        # use openscad to generate the pcb outline as dxf
        cmd = [
            "openscad",
            "-D",
            "build_case=false",
            "-o",
            self.dxf_file,
            self.scad_file,
        ]
        scad_output = subprocess.check_output(cmd, stderr=subprocess.STDOUT)
        # get key positions from openscad output
        scad_vals = np.array(
            literal_eval(scad_output.splitlines()[0][6:].decode()), dtype=object
        )
        # import the previously generated dxf as the pcb outline
        self.draw_dxf_lines(self.dxf_file, pcbnew.Edge_Cuts, self.origin_offset)
        # get row and col nets
        nets = self.board.GetNetsByName()
        row_nets = [nets[f"ROW{i+1}"] for i in range(self.max_rows)]
        col_nets = [nets[f"COL{i+1}"] for i in range(self.max_cols)]
        # add keys to the finger cluster
        self.add_finger_cluster(scad_vals[0], row_nets, col_nets)
        # add keys to the thumb cluster
        self.add_thumb_cluster(
            scad_vals[1], scad_vals[2], scad_vals[3], row_nets[-1], col_nets
        )
        # add tracks going through the column connectors
        self.add_col_connector_tracks(scad_vals[4], len(scad_vals[0][0]), pcbnew.B_Cu)

    def add_finger_cluster(self, finger_vals, row_nets, col_nets):
        """Add keys to the finger cluster"""
        off = self.origin_offset
        for i, col in enumerate(finger_vals):
            for j, pos in enumerate(col):
                ref = f"SW{i+1}{j+1}"
                self.add_key(ref, pos[:2] + off, row_nets[j], col_nets[i])
                if j > 0:
                    self.add_col_track(pos[:2] + off, col[j - 1][:2] + off, pcbnew.F_Cu)

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
                    pcbnew.F_Cu,
                    t_rot + 180,
                )

    def draw_dxf_lines(self, dxf_file, layer, off=np.zeros(2)):
        """Draw lines from a given dxf file to a specific layer"""
        dxf = dxfgrabber.readfile(dxf_file)
        for e in [e for e in dxf.entities if e.dxftype == "LINE"]:
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
        key = pcbnew.FootprintLoad(self.footprint_path, self.footprint_name)
        pads = key.Pads()
        pads[1].SetNet(row_net)
        pads[2].SetNet(col_net)
        pads[3].SetNet(col_net)
        key.SetReference(ref)
        key.Rotate(pcbnew.wxPoint(0, 0), rotation * 10)
        key.SetPosition(self.to_point(pos))
        self.board.Add(key)
        self.add_key_tracks(pos, pcbnew.F_Cu, rotation)

    def add_key_tracks(self, key_pos, layer, rotation):
        """Add tracks within each key"""
        paths = (
            [
                (-2.54, -5.08),
                (-3.81, -2.54),
            ],
            [
                (2.54, -5.08),
                (3.81, -2.54),
                (3.81, 1.905),
                (2.305, 3.41),
                (1.65, 3.41),
            ],
        )
        for path in paths:
            self.add_track_path(path, key_pos, layer, rotation)

    def add_col_track(self, pos, ppos, layer):
        """Add a track connecting the column pins of two keys"""
        diff = ppos - pos
        path = [
            (-3.81, -2.54),
            (-3.81, -0.635),
            (-4.445, 0),
            *self.angled_track_path(
                np.array((-4.445, 3.175)),
                np.array((-4.445 + max(0, diff[0]), 6.985)),
            ),
            *self.angled_track_path(
                np.array((-4.445 + max(0, diff[0]), -6.985 + diff[1])),
                np.array((-2.54, -5.08)) + diff,
            ),
        ]
        self.add_track_path(path, pos, layer)

    def add_thumb_row_track(self, pos, ppos, offset, layer, rotation):
        """Add a track connecting the row pins of two thumb pins"""
        diff = ppos - pos
        path = [
            (-1.65, 3.41) - diff,
            (-2.305, 3.41) - diff,
            (-5.715, 0) - diff,
            (-5.715, 6.82),
            (-2.305, 3.41),
            (-1.65, 3.41),
        ]
        self.add_track_path(path, offset, layer, rotation)

    def add_col_connector_tracks(self, col_connector_vals, track_count, layer):
        """Add tracks going through the column connectors"""
        off = self.origin_offset
        arc1 = self.arc_track_path(90, 0)
        arc2 = self.arc_track_path(90, 90)
        for c_type, pos1, pos2 in col_connector_vals:
            if c_type == -2:
                for d in np.linspace(-1, 1, track_count):
                    self.add_track(pos1 + off + (0, d), pos2 + off + (0, d), layer)
            else:
                r = (pos2[0] - pos1[0]) / 2
                a_r = abs(r)
                ln = abs(pos1[1] - pos2[1]) - 2 * a_r
                arc = arc1 if c_type == 0 else arc2
                for d in np.linspace(r - 1, r + 1, track_count):
                    self.add_track_path(arc * d, pos1 + off + (0, a_r), layer)
                    self.add_track(
                        pos1 + off + (d, a_r), pos1 + off + (d, a_r + ln), layer
                    )
                    self.add_track_path(arc * -d, pos2 + off - (0, a_r), layer)

    def angled_track_path(self, start, end):
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

    def arc_track_path(self, arc_angle, rotation=0):
        """Calulate the points for path describing an arc with radius 1"""
        a = np.linspace(
            rotation, arc_angle + rotation, self.arc_segments * arc_angle // 360
        )
        a_rad = np.radians(a)
        return np.array(list(zip(np.sin(a_rad), np.cos(a_rad))))

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
        track.SetWidth(self.track_width)
        self.board.Add(track)

    def save_board(self, board_file):
        """Save the board to the given output file"""
        pcbnew.SaveBoard(board_file, self.board)

    def to_point(self, pos):
        """Return a wxPoint with the given position"""
        return pcbnew.wxPointMM(*pos.tolist())


if __name__ == "__main__":
    f_dir = os.path.dirname(__file__)
    generator = GeneratePcb()
    generator.Run(os.path.join(f_dir, "template-key-matrix.kicad_pcb"))
    generator.save_board(os.path.join(f_dir, "build/key-matrix.kicad_pcb"))
else:
    GeneratePcb().register()
