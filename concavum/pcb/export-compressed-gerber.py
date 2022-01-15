#!/usr/bin/env python3

import os
import pcbnew
from shutil import make_archive
from tempfile import TemporaryDirectory


# Gerber exporter code is mostly taken from the gerber plot plugin from aster94:
# https://gist.github.com/aster94/bd52972ab6dbf13a44fc046b4222f7e7
class ExportCompressedGerber:
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
    gerber_dir = os.path.join(f_dir, "gerber")
    if not os.path.isdir(gerber_dir):
        os.mkdir(gerber_dir)
    exporter = ExportCompressedGerber()
    matrix_pcb = pcbnew.LoadBoard(
        os.path.join(f_dir, "matrix-pcb/matrix-pcb.kicad_pcb")
    )
    interface_pcb = pcbnew.LoadBoard(
        os.path.join(f_dir, "interface-pcb/interface-pcb.kicad_pcb")
    )
    exporter.export_compressed(
        matrix_pcb, os.path.join(gerber_dir, "gerber-concavum-matrix")
    )
    exporter.export_compressed(
        interface_pcb, os.path.join(gerber_dir, "gerber-concavum-interface")
    )
