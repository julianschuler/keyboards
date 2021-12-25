import os
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
        self.footprint_path = "/usr/share/kicad-nightly/footprints/"
        self.footprint_lib = "Button_Switch_Keyboard.pretty"
        self.footprint_name = "SW_Cherry_MX_1.00u_Plate"
        self.scad_file = os.path.join(os.path.dirname(__file__), "concavum-case.scad")
        self.dxf_file = os.path.join(os.path.dirname(__file__), "pcb_outline.dxf")
        self.origin_offset = [200, 100]

    def Run(self):
        """Method to be called when the plugin is executed"""
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
        off = [2.54, -5.08]
        key = pcbnew.FootprintLoad(
            self.footprint_path + self.footprint_lib, self.footprint_name
        )
        pos = pcbnew.wxPoint(pcbnew.FromMM(x + off[0]), pcbnew.FromMM(y + off[1]))
        key.Rotate(pcbnew.wxPoint(0, 0), rotation * 10)
        key.SetPosition(pos)
        self.board.Add(key)


GeneratePcb().register()
