#!/usr/bin/env python3

import os
import sys
import subprocess


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Incorrect number of arguments.\nUsage: {sys.argv[0]} [output file]")
        sys.exit(1)
    output_file = sys.argv[1]
    f_dir = os.path.dirname(__file__)
    scad_file = os.path.join(f_dir, "concavum-case.scad")
    outline = os.path.splitext(output_file)[1].lower() in [".dxf", ".svg"]
    cmd = (
        "openscad",
        "-D",
        "build_bottom_plate_outline=true" if outline else "build_bottom_plate=true",
        "-o",
        output_file,
        scad_file,
    )
    scad_output = subprocess.check_output(cmd, stderr=subprocess.STDOUT)
