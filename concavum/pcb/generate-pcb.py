#!/usr/bin/env python3

import os
import subprocess
import pcbnew
import dxfgrabber
from ast import literal_eval
from shutil import make_archive
from tempfile import TemporaryDirectory


class GeneratePcb(pcbnew.ActionPlugin):
    def defaults(self):
        """Set name and properties of the Plugin"""
        self.name = "Generate key matrix pcb"
        self.category = "Utils"
        self.description = "Generate the key matrix pcb from the openscad script"
        self.footprint_path = os.path.join(os.path.dirname(__file__), "footprints")
        self.footprint_name = "key-switch"
        self.scad_file = os.path.join(
            os.path.dirname(__file__), "../case/concavum-case.scad"
        )
        self.dxf_file = os.path.join(
            os.path.dirname(__file__), "outline-key-matrix.dxf"
        )
        self.origin_offset = [200, 100]

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
        # add all keys in the finger cluster
        for pos in [p for pos in scad_values[0] for p in pos]:
            pcbnew.FromMM(off[0] - pos[0]), pcbnew.FromMM(off[1] - pos[1])
            self.add_key(pos[0] + off[0], pos[1] + off[1])

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


# GerberExporter code is mostly taken from the gerber plot plugin from aster94:
# https://gist.github.com/aster94/bd52972ab6dbf13a44fc046b4222f7e7
class GerberExporter:
    def generate_gerber_files(self, board, path):
        plot_controller = pcbnew.PLOT_CONTROLLER(board)
        plot_options = plot_controller.GetPlotOptions()
        plot_options.SetOutputDirectory(path)
        plot_plan = [
            ("F.Cu", pcbnew.F_Cu, "Front Copper"),
            ("B.Cu", pcbnew.B_Cu, "Back Copper"),
            ("F.Paste", pcbnew.F_Paste, "Front Paste"),
            ("B.Paste", pcbnew.B_Paste, "Back Paste"),
            ("F.SilkS", pcbnew.F_SilkS, "Front SilkScreen"),
            ("B.SilkS", pcbnew.B_SilkS, "Back SilkScreen"),
            ("F.Mask", pcbnew.F_Mask, "Front Mask"),
            ("B.Mask", pcbnew.B_Mask, "Back Mask"),
            ("Edge.Cuts", pcbnew.Edge_Cuts, "Edges"),
            ("Eco1.User", pcbnew.Eco1_User, "Eco1 User"),
            ("Eco2.User", pcbnew.Eco2_User, "Eco1 User"),
        ]
        for layer_info in plot_plan:
            plot_controller.SetLayer(layer_info[1])
            plot_controller.OpenPlotfile(
                layer_info[0], pcbnew.PLOT_FORMAT_GERBER, layer_info[2]
            )
            plot_controller.PlotLayer()
        plot_controller.ClosePlot()

    def generate_drill_file(self, board, path):
        METRIC = True
        ZERO_FORMAT = pcbnew.GENDRILL_WRITER_BASE.DECIMAL_FORMAT
        INTEGER_DIGITS = 3
        MANTISSA_DIGITS = 3
        MIRROR_Y_AXIS = False
        HEADER = True
        OFFSET = pcbnew.wxPoint(0, 0)
        MERGE_PTH_NPTH = True
        DRILL_FILE = True
        MAP_FILE = False
        REPORTER = None
        drill_writer = pcbnew.EXCELLON_WRITER(board)
        drill_writer.SetFormat(METRIC, ZERO_FORMAT, INTEGER_DIGITS, MANTISSA_DIGITS)
        drill_writer.SetOptions(MIRROR_Y_AXIS, HEADER, OFFSET, MERGE_PTH_NPTH)
        drill_writer.CreateDrillandMapFilesSet(path, DRILL_FILE, MAP_FILE, REPORTER)

    def export_compressed(self, board, zip_path):
        with TemporaryDirectory() as tmp_dir:
            self.generate_gerber_files(board, tmp_dir)
            self.generate_drill_file(board, tmp_dir)
            make_archive(zip_path, "zip", tmp_dir)


if __name__ == "__main__":
    f_dir = os.path.dirname(__file__)
    generator = GeneratePcb()
    generator.Run(os.path.join(f_dir, "template-key-matrix.kicad_pcb"))
    generator.save_board(os.path.join(f_dir, "build/key_matrix.kicad_pcb"))
    exporter = GerberExporter()
    exporter.export_compressed(generator.board, "gerber-key-matrix")
else:
    GeneratePcb().register()
