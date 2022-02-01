#!/usr/bin/env python3

import os
from pcbnew import LoadBoard
from shutil import make_archive
from tempfile import TemporaryDirectory
from kikit.fab.common import ensurePassingDrc
from kikit.export import gerberImpl


def export_compressed_gerber(board, zip_path):
    # run drc before exporting the board
    ensurePassingDrc(LoadBoard(board))
    # write gerber files to a temporary directory and create archive out of it
    with TemporaryDirectory() as tmp_dir:
        gerberImpl(board, tmp_dir)
        make_archive(zip_path, "zip", tmp_dir)


if __name__ == "__main__":
    f_dir = os.path.dirname(__file__)
    gerber_dir = os.path.join(f_dir, "gerber")
    if not os.path.isdir(gerber_dir):
        os.mkdir(gerber_dir)
    # board files
    matrix_pcb_file = os.path.join(f_dir, "matrix-pcb/matrix-pcb-panel.kicad_pcb")
    interface_pcb_file = os.path.join(f_dir, "interface-pcb/interface-pcb.kicad_pcb")
    # gerber output files without the ".zip" extension
    matrix_gerber_path = os.path.join(gerber_dir, "gerber-concavum-matrix")
    interface_gerber_path = os.path.join(gerber_dir, "gerber-concavum-interface")
    # create zip archives with the compressed gerber files
    export_compressed_gerber(matrix_pcb_file, matrix_gerber_path)
    export_compressed_gerber(interface_pcb_file, interface_gerber_path)
