// decide whether to build case or pcb outline
/* build_case = true; */
build_case = false;

// decide whether to show keys and calculate shell during case preview
show_keys = false;
show_pcb = true;
calculate_shell = false;

// only regarded when build_case is false and during preview:
// if true, show a visualisation of the bending of the pcb thumb connector
visualize_bending = true;

// distance between neighbouring keys
key_distance = [19.05, 19.05];

// range for each column and thumb keys
col_range = [-1 : 2];
thumb_range = [-1 : 1];

// finger well curvature, side rotation, offset relative to the first value and chamfer
finger_angles = [20, 20, 20, 20, 20, 20];
/* finger_angles = [20, 1, 20, 20, 20, 20]; */
finger_rotation = [20, 0, 0, 0, 0, -20];
finger_offset = [[0, 0, 0], [0, 0, 0], [0, 0, -5], [0, 0, 0], [0, -20, 5], [0, -20, 5]];
/* finger_offset = [[0, 0, 0], [0, 0, 0], [0, 0, -3], [0, 0, 0], [0, -20, 5], [0, -20, 5]]; */
finger_chamfer = [0, 5.5, 7, 7];
finger_rim = 6;

// thumb well curvature, offset and rotation
thumb_angle = 20;
thumb_rotation = [30, 0, 80];
thumb_offset = [16, -50, 10] - [key_distance.x, 0, 0];
/* thumb_offset = [16, -50, 0] - [key_distance.x, 0, 0]; */
thumb_chamfer = [9, 9, 7, 9];

// keyboard tenting angle and other values
tenting_angle = 20;
height = 40;
mount_height = 80;
mount_boarder = 5;
mount_rim = [5, 3];

// key matrix pcb values
pcb_connector_width = 3;
pcb_straight_conn_width = 5;
pcb_pad_size = [12.5, 14];
pcb_thickness = 0.6;

// thumb connector values
thumb_connector_width = 3;
thumb_anker_index = 0;
finger_anker_index = [1, 0];

// switch plate values
plate_thickness = 2;
plate_indent = 1.5;

// nut and bolt values
bolt_diameter = 3.2;
nut_width = 5.5;
nut_height = 2.8;
nut_rim = [1.5, 2];

// keycap and switch values (shouldn't be changed normally)
keycap_size = [18.4, 12.3, 7.7];
switch_top_size = [15.6, 10, 6.6];
switch_bottom_size = [14, 14, 5];

// pcb values (shouldn't be changed normally)
pcb_size = [29, 40, 1.6];
pcb_offset = [0, 0, 2];
pcb_point = 3;

// port values (shouldn't be changed normally)
usb_width = 9.2;
usb_height = 3.4;
usb_radius = 1.1;
usb_offset = 14.1;
jack_radius = 3.1;
jack_offset = [5.8, 0.55];
port_offset = [4.5, 0, 1.7];

// colors
keycap_color = [0.2, 0.2, 0.2, 1];
switch_color = [0.9, 0.9, 0.9, 1];
pcb_color = [0.1, 0.1, 0.1, 1];

// rendering options
e = 0.01;
$fa = 3;
$fs = 0.01;


nut_values = [
    [5, 0, 3], [11, 0, 5.5], [8, 180, 7]
];


extra_widths = [
    [4, 0, -key_distance.x], [3, 2, 2 * key_distance.x]
];


function iter(list) = [0 : len(list) - 1];


function sum(list, s=0, i=0) = (i == len(list)) ? s : sum(list, s + list[i], i + 1);


function rotate_pos(angles, pos) = let(
    sx = sin(angles.x),
    sy = sin(angles.y),
    sz = sin(angles.z),
    cx = cos(angles.x),
    cy = cos(angles.y),
    cz = cos(angles.z),
    px = pos.x,
    py = pos.y,
    pz = pos.z
) [
    cz * cy * px + (cz * sy * sx - sz * cx) * py + (cz * sy * cx + sz * sx) * pz,
    sz * cy * px + (sz * sy * sx + cz * cx) * py + (sz * sy * cx - cz * sx) * pz,
    -sy * px + cy * sx * py + cy * cx * pz
];


function extra_width(i, j) = [for (e = extra_widths) if (e[0] == i && e[1] == j) e[2], 0][0];


function lerp(t, p0, p1) = (p1 - p0) * t + p0;


function bezier_point(t, p) = let (
    p4 = lerp(t, p[0], p[1]),
    p5 = lerp(t, p[1], p[2]),
    p6 = lerp(t, p[2], p[3]),
    p7 = lerp(t, p4, p5),
    p8 = lerp(t, p5, p6)
    )
        lerp(t, p7, p8);



function bezier_curve_length(steps, p) =
    let (step_size = 1 / steps)
    sum([for (t = [0 : step_size : 1 - step_size]) let (
        p4 = bezier_point(t, p),
        p5 = bezier_point(t + step_size, p)
        )
            norm(p5 - p4)
        ]);


finger_vals = [for (i = iter(finger_angles)) let (
    h = switch_top_size.z,
    dx = key_distance.x,
    dy = key_distance.y,
    a1 = finger_rotation[i],
    a2 = finger_angles[i],
    c1 = (a1 == 0) ? 0 : dx / 2 / tan(abs(a1 / 2)),
    c2 = (a2 == 0) ? 0 : dy / 2 / tan(a2 / 2),
    r1 = c1 + h,
    r2 = c2 + h,
    x1 = dx * (i + sign(a1)) - r1 * sin(a1),
    z1 = r1 * (1 - cos(a1)),
    off = finger_offset[i] - finger_offset[0],
    md = (h + mount_height) * tan(a2 / 2)
    ) [for (j = col_range) let (
        b2 = a2 * j,
        y2 = r2 * sin(b2),
        cs = (1 - cos(b2)),
        z2 = r2 * cs,
        x2 = -tan(a1) * (c2 * cs + dy / 2 * sin(abs(b2)))
        )
            [[x1, 0, z1] + off, [x2, y2, z2], a1, b2, md]
        ]
    ];

thumb_vals = [for (j = thumb_range) let (
    h = switch_top_size.z,
    dx = key_distance.x,
    dy = key_distance.y,
    a2 = thumb_angle,
    c2 = (a2 == 0) ? 0 : dy / 2 / tan(a2 / 2),
    r2 = c2 + h,
    md = (h + mount_height) * tan(a2 / 2),
    b2 = a2 * j,
    y2 = r2 * sin(b2),
    z2 = r2 * (1 - cos(b2))
    )
        [[0, y2, z2], b2, md]
    ];


mount_points = [for (i = [0 : len(finger_vals)]) let (
    l = len(finger_vals),
    dx = key_distance.x / 2,
    dy = key_distance.y / 2 + mount_boarder,

    vs = finger_vals[min(i, l - 1)],
    pvs = finger_vals[max(i - 1, 0)],

    m = len(vs) - 1,

    pos01 = vs[0][0],
    pos02 = vs[0][1],
    posm1 = vs[m][0],
    posm2 = vs[m][1],

    ppos01 = pvs[0][0],
    ppos02 = pvs[0][1],
    pposm1 = pvs[m][0],
    pposm2 = pvs[m][1],

    x0 = pos01.x + pos02.x + ((i == l) ? dx : -dx),
    y0 = min(pos01.y, ppos01.y) + min(pos02.y, ppos02.y) - dy,
    xm = posm1.x + posm2.x + ((i == l) ? dx : -dx),
    ym = max(posm1.y, pposm1.y) + max(posm2.y, pposm2.y) + dy

    ) each
        [[x0, y0], [xm, ym]]
    ];

mount_path = [[each [0 : 2 : 2 * (len(finger_vals))], each [2 * len(finger_vals) + 1 : -2 : 1]]];


pcb_vals = [for (i = iter(finger_vals)) let (
    h = switch_top_size.z + switch_bottom_size.z,
    vs = finger_vals[i],
    kx = key_distance.x,
    ky = key_distance.y,
    sy = pcb_pad_size.y,
    sx = pcb_pad_size.x,
    a1 = finger_rotation[i],
    a2 = finger_angles[i],
    c1 = (a1 == 0) ? 0 : (kx - sx) / 2 / tan(abs(a1 / 2)),
    r1 = c1 + h,
    dx = -(sx + (PI * r1 * abs(a1) / 180)) * sign(a1) + kx * (i + sign(a1))
    ) [for (j = iter(vs)) let (
        v = vs[j],
        pos1 = v[0],
        pos2 = v[1],
        c2 = (a2 == 0) ? 0 : (ky - sy) / 2 / tan(abs(a2 / 2)),
        r2 = c2 + h,
        dy = (sy + (PI * r2 * abs(a2) / 180)) * (j + col_range[0])
        )
            [dx + pos2.x, dy + pos1.y, pos1.z * 0]
        ]
    ];

pcb_thumb_vals = [for (i = iter(thumb_vals)) let (
    h = switch_top_size.z + switch_bottom_size.z,
    ky = key_distance.y,
    sy = pcb_pad_size.y,
    sx = pcb_pad_size.x,
    a = thumb_angle,
    r = (a == 0) ? 0 : (ky - sy) / 2 / tan(abs(a / 2)) + h,
    dy = (sy + (PI * r * a / 180)) * (i + thumb_range[0])
    )
        [0, dy]
    ];

thumb_connector_vals = let(
    // values for connector endpoints
    f_val = finger_vals[finger_anker_index.x][finger_anker_index.y],
    t_val = thumb_vals[thumb_anker_index],
    // angles
    a = thumb_rotation.z,
    b = f_val[3],
    d = t_val[1],
    // value calculations
    dy = pcb_pad_size.y / 2,
    dz = switch_bottom_size.z,
    f_off = [-f_val[0].x - f_val[1].x, f_val[0].y + f_val[1].y, f_val[0].z + f_val[1].z],
    f_pos = f_off + rotate_pos([b, 0, 0], [0, -dy, -dz]),
    t_off = [pcb_pad_size.x / 2, dz * sin(d), -dz * cos(d)],
    t_pos = thumb_offset + rotate_pos(thumb_rotation, t_val[0] + t_off),
    diff = f_pos - t_pos,
    beta = atan((1 - cos(a)) / (sin(a) * cos(b))),
    r = (abs(diff.y) * sin(a) - abs(diff.x) * cos(a)) / (1 + sin(a - beta) * (1 - cos(a)) / sin(beta)),
    f = r * tan(a / 2),
    f_arc = f_pos + rotate_pos([b, 0, 0], [f * sin(a), -f * (1 + cos(a)), 0]),
    t_arc = thumb_offset + rotate_pos(thumb_rotation, t_val[0] + t_off + [r, r * cos(d), r * sin(d)]),
    // bezier curve points
    bd = t_arc - f_arc,
    bx = sin(a) * bd.x - cos(a) * bd.y,
    bezier_points = [
        [0, 0],
        [bx / 2, 0],
        [bx - bx / 2 * cos(thumb_rotation.x + d), bd.z + bx / 2 * sin(thumb_rotation.x + d)],
        [bx, bd.z]
    ]
    ) [r, a, b, d, bezier_points, f_pos, t_pos, f_arc, f_val, t_val];



module flip_x(flip=true) {
    mirror([flip ? 1 : 0, 0, 0]) children();
}


module keycap(size) {
    color(keycap_color) scale([size, 1, 1]) rotate ([0, 0, 45])
        cylinder(keycap_size.z, d1 = keycap_size[0] * sqrt(2), d2 = keycap_size[1] * sqrt(2), $fn=4);
}


module switch() {
    color(switch_color) {
        rotate ([0, 0, 45])
            cylinder(switch_top_size.z, d1 = switch_top_size[0] * sqrt(2),
                d2 = switch_top_size[1] * sqrt(2), $fn=4);
        translate([0, 0, -switch_bottom_size[2] / 2]) cube (switch_bottom_size, center=true);
    }
}


module key(size=1) {
    switch();
    translate([0, 0, switch_top_size.z]) keycap(size);
}


module keys(angle=-tenting_angle, z_off=height) {
    if (show_keys && $preview) translate([0, 0, z_off]) rotate ([0, angle, 0]) {
        flip_x() for (i = iter(finger_vals)) {
            vs = finger_vals[i];
            for (j = iter(vs)) {
                pos1 = vs[j][0];
                pos2 = vs[j][1];
                a1 = vs[j][2];
                a2 = vs[j][3];
                translate(pos1) rotate([0, a1, 0]) translate(pos2) rotate([a2, 0, 0]) key();
            }
        }
        translate(thumb_offset) rotate(thumb_rotation) for (v = thumb_vals) {
            pos = v[0];
            a = v[1];
            pw = v[2];
            translate(pos) rotate([a, 0, 0]) key(1.5);
        }
    }
}


module pcb() {
    if (show_pcb && $preview) {
        pos = mount_points[pcb_point];
        x = -pos.x;
        y = pos.y - pcb_size.y / 2 - plate_thickness;
        z = pcb_size.z / 2;
        color(pcb_color) translate([x, y, z] + pcb_offset) cube(pcb_size, center=true);
    }
}


module switch_cutout() {
    cube(switch_bottom_size + [0, 0, 2 * plate_thickness], center=true);
    translate([0, 0, -plate_thickness / 2 - plate_indent])
        cube([switch_bottom_size[0], switch_top_size[0], plate_thickness], center=true);
}


module switch_cutouts() {
    translate([0, 0, height]) rotate ([0, -tenting_angle, 0]) {
        flip_x() for (i = iter(finger_vals)) {
            vs = finger_vals[i];
            for (j = iter(vs)) {
                pos1 = vs[j][0];
                pos2 = vs[j][1];
                a1 = vs[j][2];
                a2 = vs[j][3];
                translate(pos1) rotate([0, a1, 0]) translate(pos2) rotate([a2, 0, 0]) switch_cutout();
            }
        }
        translate(thumb_offset) rotate(thumb_rotation) for (v = thumb_vals) {
            pos = v[0];
            a = v[1];
            translate(pos) rotate([a, 0, 0]) switch_cutout();
        }
    }
}


module port_cutouts(left=true) {
    w = usb_width;
    l = usb_height;
    r = usb_radius;
    o = usb_offset;
    jr = jack_radius;
    jo = jack_offset;
    h = plate_thickness + 2 * e;
    pos = mount_points[pcb_point];
    x = -pos.x;
    y = pos.y - plate_thickness / 2;
    z = pcb_size.z;
    translate([x, y, z] + pcb_offset + port_offset) rotate([90, 0, 0]) if (left) {
        translate([jo[0] - o, 0, 0]) minkowski() {
            cube([w - 2 * r, l - 2 * r, h - e], center=true);
            cylinder(e, r=r, center=true);
        }
        translate(jo) cylinder(h, r=jr, center=true);
    }
    else {
        translate([0, jo.y, 0]) cylinder(h, r=jr, center=true);
    }
}


module finger_cluster() {
    w = keycap_size.x / 2 - switch_bottom_size.x / 2;
    d = key_distance.x - keycap_size.x + e;
    dy = key_distance.y;
    h = switch_top_size.z;
    s = -col_range[0];
    flip_x() intersection() {
        translate([0, 0, height]) rotate ([0, tenting_angle, 0]) for (i = iter(finger_vals)) {
            vs = finger_vals[i];
            l = (i == 0) ? true : finger_vals[i - 1][s][0].z >= finger_vals[i][0][0].z;
            r = (i == len(finger_vals) - 1) ? true : finger_vals[i][s][0].z < finger_vals[i + 1][s][0].z;
            cl = (i == 0) ? 0 : finger_vals[i - 1][0][2] + finger_vals[i][0][2];
            cr = (i == len(finger_vals) - 1) ? 0 : finger_vals[i][0][2] + finger_vals[i + 1][0][2];
            cdl = (h + mount_height) * tan(abs(cl / 2));
            cdr = (h + mount_height) * tan(abs(cr / 2));
            cm = vs[len(vs) - 1][1].x;
            for (j = iter(vs)) {
                v = vs[j];
                pos1 = v[0];
                pos2 = v[1];
                a1 = v[2];
                a2 = v[3];
                md = v[4];
                xw = extra_width(i, j);
                co = cm - pos2.x;
                o = co / 2 + ((cdl != 0) ? -cdl / 2 : (l ? -d / 2 : 0))
                    + ((cdr != 0) ? cdr / 2 : (r ? d / 2 : 0)) + xw / 2;
                ml = keycap_size.x + abs(co) + abs(xw)
                    + ((cdl != 0) ? cdl : (l ? d : 0)) + ((cdr != 0) ? cdr : (r ? d : 0));
                mw = dy + md + ((j == 0 || j == len(vs) - 1) ? mount_rim.y : md);
                mo = ((j == 0) ? (md - mount_rim.y) / 2 : (j == len(vs) - 1) ? (mount_rim.y - md) / 2 : 0);
                translate(pos1) rotate([0, a1, 0]) translate(pos2) rotate([a2, 0, 0])
                    translate([o, mo, -mount_height / 2]) cube([ml, mw, mount_height], center=true);
            }
        }
        difference() {
            linear_extrude(mount_height) polygon(mount_points, mount_path, convexity=10);
            for (i = [0, 1]) for (j = [0, 1]) {
                pos = mount_points[i * (len(mount_points) - 2) + j];
                d = sqrt(2) * finger_chamfer[2 * i + j];
                translate([pos.x, pos.y, mount_height / 2 - e])
                    rotate([0, 0, -45 + 90 * (i + j)]) cube([d + 10, d, mount_height], center=true);
            }
        }
    }
}


module thumb_cluster() {
    l = keycap_size.x * 1.5 + 2 * mount_rim.x;
    dy = key_distance.y;
    oy = 2;
    ml = l;
    mw = key_distance.y + 2 * mount_rim.y;
    intersection() {
        translate([0, 0, height]) rotate ([0, -tenting_angle, 0])
            translate(thumb_offset) rotate(thumb_rotation) for (i = iter(thumb_vals)) {
                v = thumb_vals[i];
                pos = v[0];
                a = v[1];
                md = v[2];
                w = dy + md + ((i == 0 || i == len(thumb_vals) - 1) ? mount_rim.y : md);
                mo = ((i == 0) ? (md - mount_rim.y) / 2 : (i == len(thumb_vals) - 1) ? (mount_rim.y - md) / 2 : 0);
                translate(pos) rotate([a, 0, 0])
                    translate([0, mo, -mount_height / 2]) cube([l, w, mount_height], center=true);
            }
        difference() {
            translate([thumb_offset.x, thumb_offset.y, 0]) rotate([0, 0, thumb_rotation.z]) difference() {
                for (v = thumb_vals) {
                    pos = v[0];
                    x = pos.x;
                    y = pos.y + oy;
                    translate([x, y, mount_height / 2]) cube([ml, mw, mount_height], center=true);
                }
                for (i = [0, 1]) {
                    pos = thumb_vals[i * (len(thumb_vals) - 1)][0];
                    for (j = [0, 1]) {
                        d = sqrt(2) * thumb_chamfer[2 * i + j];
                        x = pos.x + sign(j - 0.5) * ml / 2;
                        y = pos.y + sign(i - 0.5) * mw / 2 + oy;
                        translate([x, y, mount_height / 2 - e])
                            rotate([0, 0, 45]) cube([d, d, mount_height], center=true);
                    }
                }
            }
            flip_x() linear_extrude(mount_height) offset(delta=-finger_rim)
                polygon(mount_points, mount_path, convexity=10);
        }
    }
}


module nut_holder(angle=0) {
    h = nut_rim[0] + nut_height;
    w = nut_width + 2 * nut_rim[1];
    t = max(plate_thickness, nut_rim[1]) + nut_width / 2;
    rotate([0, 0, angle]) translate([0, -t, 0]) difference() {
        union() {
            cylinder(h, d=w / cos(30), $fn=6);
            translate([-w / 2 / cos(30), 0, 0]) cube([w / cos(30), t, h]);
        }
        translate([0, 0, -e]) cylinder(nut_rim[0] + 2 * e, d=bolt_diameter);
        translate([0, 0, nut_rim[0]]) cylinder(nut_height + e, d=nut_width / cos(30), $fn=6);
    }
}


module nut_holders() {
    l = keycap_size.x * 0.75 + mount_rim.x;
    dy = thumb_offset.y + 2.5;
    flip_x() for (v = nut_values) {
        pos = mount_points[v[0]] + [v[2], 0];
        a = v[1];
        translate(pos) nut_holder(a);
    }
    translate([thumb_offset.x, dy, 0]) rotate([0, 0, thumb_rotation.z + 90]) translate([0, l, 0])
        nut_holder(0);
}


module pcb_holder() {
    l1 = 2;
    l2 = 10;
    h1 = pcb_offset.z;
    h2 = h1 + pcb_size.z;
    pos = mount_points[pcb_point];
    x1 = -pos.x + pcb_offset.x;
    x2 = -mount_points[0].x;
    y1 = pos.y + l1 / 2 - plate_thickness + pcb_offset.y - pcb_size.y;
    y2 = pos.y - pcb_size.y - plate_thickness + pcb_offset.y - l2 / 2;
    w1 = pcb_size.x / 3;
    w2 = x2 - x1 + w1 / 2;
    translate([x1, y1, h1 / 2]) cube([w1, l1 + 2 * e, h1], center=true);
    translate([x2 - w2 / 2, y2, h2 / 2]) cube([w2, l2, h2], center=true);
}


module mount(left=true) {
    translate([(left ? -40 : 40), 0, 0]) flip_x(!left) {
        difference() {
            // main body
            union() {
                shell(plate_thickness) union() {
                    finger_cluster();
                    thumb_cluster();
                }
                nut_holders();
                pcb_holder();
            }
            // cutouts
            switch_cutouts();
            port_cutouts(left);
        }
        // preview elements
        keys();
        pcb();
    }
}


module shell(t) {
    intersection() {
        children(0);
        if (calculate_shell || !$preview) {
            minkowski() {
                difference() {
                    translate([0, 0, 500]) cube([1000, 1000, 1000], center=true);
                    children(0);
                }
                sphere(r=t, $fn=10);
            }
        }
    }
}


module case() {
    // left half
    mount(left=true);
    // right half
    mount(left=false);
}


module pcb_pad_with_connector(conn_l, conn_x, conn_y) {
    difference() {
        union() {
            square(pcb_pad_size, center=true);
            translate([conn_x, conn_y]) {
                square([pcb_straight_conn_width, conn_l]);
            }
        }
        circle(d=4);
    }
}


module arc(r, w, angle=90) {
    intersection() {
        difference() {
            circle(r=r + w / 2);
            circle(r=r - w / 2);
        }
        translate([r / 2 + w / 2 - e, e])
            square([r + w + 2 * e, 2 * r + w + 2 * e], center=true);
        rotate([0, 0, -angle]) translate([-r / 2 - w / 2 + e, e])
            square([r + w + 2 * e, 2 * r + w + 2 * e], center=true);
    }
}


module line(l, w) {
    translate([-w / 2, 0]) square([w, l]);
}


module connector(pcb_pos, ppcb_pos, w, left=true) {
    pos1 = ((left) ? pcb_pos : ppcb_pos) + [((left) ? -1 : 1) * pcb_pad_size.x / 2, pcb_pad_size.y / 2 - w / 2];
    pos2 = ((left) ? ppcb_pos : pcb_pos) + [((left) ? 1 : -1) * (pcb_pad_size.x / 2 - w / 2), -pcb_pad_size.y / 2];
    r = abs(pos1.x - pos2.x) / 3;
    l = abs(pos2.y - pos1.y) - r;
    translate(pos1) flip_x(left) {
        translate([0, -r]) arc(r, w);
        translate([r, -r - l]) line(l, w);
        translate([2 * r, -r - l]) rotate(-90) arc(r, w, 180);
    }
}


/* module thumb_connector(t_pos, f_pos, t_angle, w) { */
/*     d = f_pos - t_pos; */
/*     r = (d.x * tan(t_angle) - d.y) / (tan(t_angle) - 2 / cos(t_angle)); */
/*     l = 2 * r * tan(t_angle) + (d.x - r) / cos(t_angle) - r; */
/*     translate(t_pos) { */
/*         rotate(t_angle + 90) translate([0, -r]) arc(r, w); */
/*         rotate(t_angle - 90) translate([-r, r]) line(l, w); */
/*     } */
/*     translate(f_pos + [-r, 0]) rotate(-90) arc(r, w, 90 - t_angle); */
/* } */


module thumb_connector() {
    r = thumb_connector_vals[0];
    a = thumb_connector_vals[1];
    b = thumb_connector_vals[2];
    d = thumb_connector_vals[3];
    bezier_points = thumb_connector_vals[4];
}


module thumb_connector_visualisation() {
    r = thumb_connector_vals[0];
    a = thumb_connector_vals[1];
    b = thumb_connector_vals[2];
    d = thumb_connector_vals[3];
    bezier_points = thumb_connector_vals[4];
    f_pos = thumb_connector_vals[5];
    t_pos = thumb_connector_vals[6];
    f_arc = thumb_connector_vals[7];
    f_val = thumb_connector_vals[8];
    t_val = thumb_connector_vals[9];

    // arcs
    translate(f_pos)
        rotate([b, 0, 0]) rotate(90)
        translate([0, -r, -pcb_thickness]) flip_x() linear_extrude(pcb_thickness)
        arc(r, 3, a);
    translate(t_pos)
        rotate(thumb_rotation + [d, 0, 0])
        rotate(-90)
        translate([-r, 0, -pcb_thickness]) linear_extrude(pcb_thickness)
        arc(r, 3);
    // bending part of the connector approximated with a bezier curve
    translate(f_arc) rotate(a - 90) {
        for (t = [0 : 0.005 : 1]) {
            pos = bezier_point(t, bezier_points);
            angle = (thumb_rotation.y - b) * t + b;
            translate([pos[0], 0, pos[1]]) rotate([angle, 0])
            translate([0, 0, -pcb_thickness / 2])
                cube([0.2, thumb_connector_width, pcb_thickness], center=true);
        }
    }

    // keys
    flip_x() translate(f_val[0]) rotate([0, f_val[2], 0])
        translate(f_val[1]) rotate([f_val[3], 0, 0]) key();
    translate(thumb_offset) rotate(thumb_rotation)
        translate(t_val[0]) rotate([t_val[1], 0, 0]) key(1.5);
}

module pcb_outline() {
    // finger cluster
    flip_x() for (i = iter(finger_vals)) {
        vs = finger_vals[i];
        ps = pcb_vals[i];
        s = -col_range[0];
        if (i > 0) {
            a = finger_vals[i - 1][0][2] + finger_vals[i][0][2];
            if (a != 0) {
                conn_l = ps[s].x - pcb_vals[i - 1][s].x - pcb_pad_size.x + 2 * e;
                conn_x = -pcb_pad_size.x / 2 + e;
                translate(pcb_vals[i-1][s] - [conn_x, pcb_straight_conn_width / 2]) {
                    square([conn_l, pcb_straight_conn_width]);
                }
            }
            else {
                left = finger_vals[i - 1][s][0].z >= finger_vals[i][s][0].z;
                connector(ps[s], pcb_vals[i - 1][s], pcb_connector_width, left);
            }
        }
        for (j = iter(vs)) {
            v = vs[j];
            pos1 = v[0];
            pos2 = v[1];
            a1 = v[2];
            a2 = v[3];
            pcb_pos = ps[j];
            ppcb_pos = ps[max(j - 1, 0)];
            conn_l = pcb_pos.y - ppcb_pos.y - pcb_pad_size.y + 2 * e;
            conn_x = (-pcb_straight_conn_width + ppcb_pos.x - pcb_pos.x) / 2;
            conn_y = -conn_l - pcb_pad_size.y / 2 + e;
            translate(pcb_pos) pcb_pad_with_connector(conn_l, conn_x, conn_y);
        }
    }
    // Approximate bending of the connector between thumb and finger cluster
    // with a bezier curve and calculate resulting length offset.
    // Bezier curve control points were empirically chosen to reduce curvature
    // while following the given constraints (see bending_approximation.py).
    // TODO: Implement actual calculations
    len_off = 0;
    // thumb cluster
    translate([thumb_offset.x, thumb_offset.y])
    rotate(thumb_rotation.z) translate([0, -len_off])
    for (i = iter(pcb_thumb_vals)) {
        pos = pcb_thumb_vals[i];
        ppos = pcb_thumb_vals[max(i - 1, 0)];
        conn_l = pos.y - ppos.y - pcb_pad_size.y + 2 * e;
        conn_x = -pcb_straight_conn_width / 2;
        conn_y = -conn_l - pcb_pad_size.y / 2 + e;
        translate(pos) pcb_pad_with_connector(conn_l, conn_x, conn_y);
    }
    // thumb connector
    a = thumb_rotation.z;
    ps = pcb_pad_size;
    w = thumb_connector_width;
    f_pos = pcb_vals[finger_anker_index.x][finger_anker_index.y] - [0, ps.y] / 2;
    t_off = [thumb_offset.x, thumb_offset.y];
    t_val = pcb_thumb_vals[thumb_anker_index] + [ps.x, -2 * len_off] / 2;
    t_pos = [-t_off.x - t_val.x * cos(a) + t_val.y * sin(a),
              t_off.y + t_val.x * sin(a) + t_val.y * cos(a)];
    pos = pcb_thumb_vals[thumb_anker_index];
    /* flip_x() thumb_connector(t_pos, f_pos, 90 - a, w); */
}



if (build_case) {
    case();
}
else if ($preview) {
    translate([0, 0, -switch_bottom_size.z - pcb_thickness])
    linear_extrude(pcb_thickness)
    pcb_outline();

    if (visualize_bending) thumb_connector_visualisation();
    keys(0, 0);
}
else {
    pcb_outline();
}
