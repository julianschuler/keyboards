// output settings
$fa = 6;
$fs = 0.01;
show_cutout = true;
nut_side_insert = false;
show_finished = true;
// variables
layer_height = 0.2;
bolt_diameter = 3.2;
bolt_len = 10;
key_colums = 3;
key_rows = 2;
key_distance = 19.05;
key_offset = 0;
plate_angle = 10;
flat_len = 68;
encoder_diameter = 6.8;
encoder_width = 14;
encoder_offset = 47;
nut_offset = 5;
nut_width = 5.5;
nut_height = 2.8;
usb_height = 6.6;
usb_width = 12.3;
usb_length = 25;
usb_offset = 1;
extra = 15;
e = 0.01;
// derived variables
plate_len = flat_len * cos(plate_angle);
t = plate_len * tan(plate_angle);


// blender model for reference
module manuform() {
  import("manuform-closed.stl", convexity=5);
}

// cutout for a single key
module key_cutout() {
  union() {
    translate([0, 0, 3 - extra/2]) cube([13.9, 13.9, 6 + extra], center=true);
    translate([0, 4.46, 3 - extra/2]) 
      cube([15.6, 3.1, 6 + extra], center=true);
    translate([0, -4.46, 3 - extra/2]) 
      cube([15.6, 3.1, 6 + extra], center=true);
    translate([0, 0, 2 - extra/2]) cube([15.6, 15.6, 4 + extra], center=true);
  }
}


module encoder_cutout() {
  union() {
    cylinder(6, d=encoder_diameter);
    translate([-encoder_width/2, -encoder_width/2, -extra]) 
      cube([encoder_width, encoder_width, 1.3 + extra]);
  }
}



module nut_cutout(angle) {
  translate([0, 0, nut_offset + e]) rotate([0, 0, angle + 90]) {
      cylinder(nut_height, d=nut_width / cos(30), $fn=6);
      translate([0, 0, nut_height + (layer_height - e) / 2]) 
        cube([bolt_diameter, nut_width, layer_height + e], center=true);
      translate([0, 0, nut_height + (layer_height * 3 - e) / 2]) 
        cube([bolt_diameter, bolt_diameter, layer_height + e], center=true);
      if (nut_side_insert) {
        translate([0, -nut_width/2, 0]) cube([extra, nut_width, nut_height]);
      }
    }
}


module bolt_nut_cutout(x, y, angle=0) {
  translate([x, y, -e]) {
    cylinder(bolt_len, d=bolt_diameter + e);
    nut_cutout(angle);
  }
  translate([-x, y, -e]) {
    cylinder(bolt_len, d=bolt_diameter + e);
    nut_cutout(-angle);
  }
}


module usb_cutout() {
  len = usb_length + extra;
  width = usb_width - usb_height;
  height = usb_height / 2 + usb_offset;
  translate([0, extra - len/2 - e, height]) 
    cube([width, len + e, usb_height], center=true);
  translate([width / 2, extra - e, height]) rotate([90, 0, 0])
    cylinder(len, d=usb_height);
  translate([-width / 2, extra - e, height]) rotate([90, 0, 0])
    cylinder(len, d=usb_height);
}


// cutout for keys, encoders, bolts, nuts and usb adapter
module cutout() {
  translate([0, -8, 30.18]) rotate([plate_angle, 0, 0]) 
      translate([0, 8 + key_offset, 0]) union() {
      // for keys
      translate([-key_distance, 0, -0.064]) for (i = [0:key_rows-1]) {
        for (j = [0:key_colums-1]) {
          translate([j * key_distance, i * key_distance, 0]) key_cutout();
        }
      }
      // for encoder
      translate([0, encoder_offset, 0]) encoder_cutout();
    }
  // for bolts
  bolt_nut_cutout(40, -24, -40);
  bolt_nut_cutout(119.5, -17.5, 40);
  bolt_nut_cutout(127, 58, 160);
  bolt_nut_cutout(58.5, 60, 190);
  // for usb adapter
  translate([0, 67.5, 0]) usb_cutout();
}


module addition() {
  translate([0, -8, 35.7]) intersection() {
    translate([-40, t * sin(plate_angle), -t * cos(plate_angle)]) 
      rotate([plate_angle, 0, 0]) cube([80, plate_len, t]);
    translate([-40, 0, -1]) 
      cube([80, flat_len + extra, t * cos(plate_angle) + 1]);
    translate([0, 35, 25]) rotate([0, 45, 0]) cube([80, 80, 80], center=true);
    translate([0, 35, -40]) rotate([plate_angle, 0, 0]) 
      cylinder(50, r=50, $fn=24);
  }
  translate([0, 67.5 - usb_length / 2, usb_height / 2 + usb_offset]) 
    cube([18, usb_length, usb_height + usb_offset * 2], center=true);
  translate([0, 23 - (usb_length - e) / 2, usb_offset / 2]) 
    cube([18, 89 - usb_length + e, usb_offset], center=true);
}



// show everything in preview mode but render only selected object
if ($preview) {
  if (show_finished) {
    import("manuform.stl");
  }
  else {
    difference() {
      union() {
        manuform();
        addition();
      }
      cutout();
    }
  }
  color("grey") {
    translate([0, -8, 36]) rotate([plate_angle, 0, 0]) 
      translate([0, 8 + key_offset, 0]) {
        translate([0, encoder_offset, 0])  cylinder(14, d=20);
        translate([-key_distance, 0, 10]) for (i = [0:key_rows-1]) {
          for (j = [0:key_colums-1]) {
            translate([j * key_distance, i * key_distance, 0]) 
              cube([18, 18, 20], center=true);
          }
        }
      }
    translate([0, 18, 11]) cube([18, 48, 20], center=true);
  }
}
else if (show_cutout) {
  cutout();
}
else {
  addition();
}
