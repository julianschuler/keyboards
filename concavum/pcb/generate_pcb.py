import os
import subprocess
import pcbnew
import dxfgrabber
from ast import literal_eval


class GeneratePcb(pcbnew.ActionPlugin):
    def defaults(self):
        self.name = "Generate key matrix pcb"
        self.category = "Utils"
        self.description = "Generate the key matrix pcb from the openscad script"
        self.footprint_path = "/usr/share/kicad-nightly/footprints/"
        self.footprint_lib = "Button_Switch_Keyboard.pretty"
        self.footprint_name = "SW_Cherry_MX_1.00u_Plate"
        self.scad_file = os.path.join(os.path.dirname(__file__), "concavum-case.scad")
        self.dxf_file = os.path.join(os.path.dirname(__file__), "pcb_outline.dxf")
        self.origin_offset = [200, 100]
        self.key_offset = [2.54, -5.08]

    def Run(self):
        self.board = pcbnew.GetBoard()

        cmd = [
            "openscad",
            "-D",
            "build_case=false",
            "-o",
            self.dxf_file,
            self.scad_file,
        ]
        scad_output = subprocess.check_output(cmd, stderr=subprocess.STDOUT)
        pos_list = literal_eval(scad_output.splitlines()[0][6:].decode())

        self.draw_scad_dxf(self.dxf_file, pcbnew.Edge_Cuts)

        # automatic delete causes a segfault, everything has to be deleted manually
        # board.DeleteAllFootprints()

        off = list(map(sum, zip(self.origin_offset, self.key_offset)))
        for pos in [p for pos in pos_list for p in pos]:
            key = pcbnew.FootprintLoad(
                self.footprint_path + self.footprint_lib, self.footprint_name
            )
            p = pcbnew.wxPoint(
                pcbnew.FromMM(off[0] - pos[0]), pcbnew.FromMM(off[1] - pos[1])
            )
            key.SetPosition(p)
            self.board.Add(key)

    def draw_scad_dxf(self, dxf_file, layer):
        dxf = dxfgrabber.readfile(dxf_file)
        off = self.origin_offset
        for e in [e for e in dxf.entities if e.dxftype == "LINE"]:
            start = (off[0] + e.start[0], off[1] - e.start[1])
            end = (off[0] + e.end[0], off[1] - e.end[1])
            self.draw_line(start, end, layer)

    def draw_line(self, start, end, layer):
        seg = pcbnew.PCB_SHAPE(self.board)
        seg.SetLayer(layer)
        seg.SetShape(pcbnew.S_SEGMENT)
        seg.SetStart(pcbnew.wxPoint(*map(pcbnew.FromMM, start)))
        seg.SetEnd(pcbnew.wxPoint(*map(pcbnew.FromMM, end)))
        self.board.Add(seg)


GeneratePcb().register()
