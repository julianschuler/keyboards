#!/usr/bin/env python3

import os
import math
import subprocess
import pcbnew
import dxfgrabber
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
        self.origin_offset = [195, 90]
        self.max_rows = 6
        self.max_cols = 8

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
        scad_vals = literal_eval(scad_output.splitlines()[0][6:].decode())
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

    def add_finger_cluster(self, finger_vals, row_nets, col_nets):
        """Add keys to the finger cluster"""
        off = self.origin_offset
        for i, col in enumerate(finger_vals):
            for j, pos in enumerate(col):
                ref = f"SW{i+1}{j+1}"
                self.add_key(
                    ref, pos[0] + off[0], pos[1] + off[1], row_nets[j], col_nets[i]
                )

    def add_thumb_cluster(self, t_rot, t_off, thumb_vals, row_net, col_nets):
        """Add keys to the thumb cluster"""
        off = self.origin_offset
        t_rot_rad = math.radians(t_rot)
        t_sin, t_cos = math.sin(t_rot_rad), math.cos(t_rot_rad)
        for i, t_pos in enumerate(thumb_vals):
            x = t_sin * t_pos[1] + t_off[0] + off[0]
            y = t_cos * t_pos[1] - t_off[1] + off[1]
            col = len(thumb_vals) - 1 - i
            self.add_key(f"SW{i+1}", x, y, row_net, col_nets[col], t_rot + 180)

    def draw_dxf_lines(self, dxf_file, layer, off=[0, 0]):
        """Draw lines from a given dxf file to a specific layer"""
        dxf = dxfgrabber.readfile(dxf_file)
        for e in [e for e in dxf.entities if e.dxftype == "LINE"]:
            start = (off[0] + e.start[0], off[1] - e.start[1])
            end = (off[0] + e.end[0], off[1] - e.end[1])
            self.draw_line(start, end, layer)

    def draw_line(self, start, end, layer):
        """Draw a line to the given layer specified by its start and end point"""
        seg = pcbnew.PCB_SHAPE(self.board)
        seg.SetLayer(layer)
        seg.SetShape(pcbnew.S_SEGMENT)
        seg.SetStart(pcbnew.wxPoint(*map(pcbnew.FromMM, start)))
        seg.SetEnd(pcbnew.wxPoint(*map(pcbnew.FromMM, end)))
        self.board.Add(seg)

    def add_key(self, ref, x, y, row_net, col_net, rotation=0):
        """Add a single key to a given (x, y) position"""
        key = pcbnew.FootprintLoad(self.footprint_path, self.footprint_name)
        pos = pcbnew.wxPoint(pcbnew.FromMM(x), pcbnew.FromMM(y))
        pads = key.Pads()
        for i in range(1, 4):
            pads[i].SetNet(row_net)
        for i in range(4, 6):
            pads[i].SetNet(col_net)
        key.SetReference(ref)
        key.Rotate(pcbnew.wxPoint(0, 0), rotation * 10)
        key.SetPosition(pos)
        self.board.Add(key)

    def save_board(self, board_file):
        """Save the board to the given output file"""
        pcbnew.SaveBoard(board_file, self.board)


if __name__ == "__main__":
    f_dir = os.path.dirname(__file__)
    generator = GeneratePcb()
    generator.Run(os.path.join(f_dir, "template-key-matrix.kicad_pcb"))
    generator.save_board(os.path.join(f_dir, "build/key-matrix.kicad_pcb"))
else:
    GeneratePcb().register()
