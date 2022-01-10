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
        scad_values = literal_eval(scad_output.splitlines()[0][6:].decode())
        # import the previously generated dxf as the pcb outline
        off = self.origin_offset
        self.draw_dxf_lines(self.dxf_file, pcbnew.Edge_Cuts, off)
        # add keys to the finger cluster
        for pos in [p for pos in scad_values[0] for p in pos]:
            self.add_key(pos[0] + off[0], pos[1] + off[1])
        # add keys to the thumb cluster
        t_rot = scad_values[1]
        t_rot_rad = math.radians(t_rot)
        t_off = scad_values[2]
        t_sin, t_cos = math.sin(t_rot_rad), math.cos(t_rot_rad)
        for t_pos in scad_values[3]:
            x = t_sin * t_pos[1] + t_off[0] + off[0]
            y = t_cos * t_pos[1] - t_off[1] + off[1]
            self.add_key(x, y, t_rot + 180)

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

    def add_key(self, x, y, rotation=0):
        """Add a single key to a given (x, y) position"""
        key = pcbnew.FootprintLoad(self.footprint_path, self.footprint_name)
        pos = pcbnew.wxPoint(pcbnew.FromMM(x), pcbnew.FromMM(y))
        key.Rotate(pcbnew.wxPoint(0, 0), rotation * 10)
        key.SetPosition(pos)
        self.board.Add(key)

    def save_board(self, board_file):
        pcbnew.SaveBoard(board_file, self.board)


if __name__ == "__main__":
    f_dir = os.path.dirname(__file__)
    generator = GeneratePcb()
    generator.Run(os.path.join(f_dir, "template-key-matrix.kicad_pcb"))
    generator.save_board(os.path.join(f_dir, "build/key-matrix.kicad_pcb"))
else:
    GeneratePcb().register()
