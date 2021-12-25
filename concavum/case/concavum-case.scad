// select whether to build case or key matrix pcb outline
build_case = true;

// select whether to show the keys and interface pcb and
// whether to calculate the shell during case preview
show_keys = true;
show_pcb = true;
calculate_shell = true;

// if true, show a visualisation of the bending of the pcb thumb connector
visualize_bending = true;
// number of segments used to visualize the bending segment
bending_visualisation_segs = 500;

// shell thickness and $fn value for the shell calculation:
// The shell calculation may fail for certain combinations, you may need
// to adjust shell_fn to make it work. Keep in mind that higher values will
// increase the calculation time significantly.
shell_thickness = 2;
shell_fn = 15;

// distance between neighbouring keys
key_distance = [19.05, 19.05];

// range for each column and thumb keys
col_range = [-1 : 2];
thumb_range = [-1 : 1];

// finger well curvature, side rotation and offset relative to the first value
finger_angles = [20, 20, 20, 20, 20, 20];
finger_rotation = [20, 0, 0, 0, 0, -20];
finger_offset = [
    [0, 0, 0], [0, 0, 0], [0, 0, -3], [0, 0, 0], [0, -20, 5], [0, -20, 5]
];

// thumb well curvature, offset and rotation
thumb_angle = 15;
thumb_rotation = [30, 0, 80];
thumb_offset = [16, -50, 0] - [key_distance.x, 0, 0];

// finger and thumb chamfer depths and rim values
finger_chamfer = [0, 5.5, 7, 7];
finger_rim = 6;
thumb_chamfer = [6, 6, 7, 9];

// keyboard tenting angle and other values
tenting_angle = 20;
height = 40;
mount_height = 80;
mount_boarder = 5;
mount_rim = [5, 3];

// key matrix pcb values
m_pcb_connector_width = 3;
m_pcb_straight_conn_width = 5;
m_pcb_pad_size = [12.5, 14];
m_pcb_thickness = 0.6;

// thumb connector values
thumb_connector_width = 3;
finger_anchor_index = [2, 0];
thumb_anchor_index = 0;
finger_anchor_offset = (m_pcb_pad_size.x - thumb_connector_width) / 2;
thumb_anchor_offset = 0;

// polygon indices to specify where the nut holders are to be added
// format: [i, rotation, offset]
nut_values = [
    [5, 0, 3], [11, 0, 5.5], [8, 180, 7]
];

// finger indices where extra width is to be added
// format: [col, row, extra_width_amount]
extra_widths = [
    [4, 0, -key_distance.x], [3, 2, 2 * key_distance.x], [3, 3, 2 * key_distance.x]
];

// colors
keycap_color = "#333333";
switch_color = "#E6E6E6";
matrix_pcb_color = "#167A24";
interface_pcb_color = "#1A1A1A";

// rendering options (sensible defaults for 3D printings)
e = 0.01;
$fa = 3;
$fs = 0.01;

// nut and bolt values (shouldn't have to be changed)
bolt_diameter = 3.2;
nut_width = 5.5;
nut_height = 2.8;
nut_rim = [1.5, 2];

// keycap and switch values (shouldn't have to be changed)
keycap_size = [18.4, 12.3, 7.7];
switch_top_size = [15.6, 10, 6.6];
switch_bottom_size = [14, 14, 5];
plate_indent = 1.5;

// interface pcb values (shouldn't have to be changed)
i_pcb_size = [29, 40, 1.6];
i_pcb_offset = [0, 0, 2];
i_pcb_mount_point_index = 3;

// port values (shouldn't have to be changed)
usb_width = 9.2;
usb_height = 3.4;
usb_radius = 1.1;
usb_offset = 14.1;
jack_radius = 3.1;
jack_offset = [5.8, 0.55];
port_offset = [4.5, 0, 1.7];


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

function extra_width(i, j) = [for (e = extra_widths)
    if (e[0] == i && e[1] == j) e[2], 0][0];

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

mount_path = [[
    each [0 : 2 : 2 * (len(finger_vals))],
    each [2 * len(finger_vals) + 1 : -2 : 1]
]];

m_pcb_vals = [for (i = iter(finger_vals)) let (
    h = switch_top_size.z + switch_bottom_size.z,
    vs = finger_vals[i],
    kx = key_distance.x,
    ky = key_distance.y,
    sy = m_pcb_pad_size.y,
    sx = m_pcb_pad_size.x,
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
            [dx + pos2.x, dy + pos1.y, 0]
        ]
    ];

m_pcb_thumb_vals = [for (i = iter(thumb_vals)) let (
    h = switch_top_size.z + switch_bottom_size.z,
    ky = key_distance.y,
    sy = m_pcb_pad_size.y,
    sx = m_pcb_pad_size.x,
    a = thumb_angle,
    r = (a == 0) ? 0 : (ky - sy) / 2 / tan(abs(a / 2)) + h,
    dy = (sy + (PI * r * a / 180)) * (i + thumb_range[0])
    )
        [0, dy, 0]
    ];

thumb_connector_vals = let(
    // values for connector endpoints
    f_val = finger_vals[finger_anchor_index.x][finger_anchor_index.y],
    t_val = thumb_vals[thumb_anchor_index],
    // angles
    a = thumb_rotation.z,
    b = f_val[3],
    c = thumb_rotation.y,
    d = t_val[1],
    // value calculations
    dy = m_pcb_pad_size.y / 2,
    dz = switch_bottom_size.z,
    f_off = [
        -f_val[0].x - f_val[1].x, f_val[0].y + f_val[1].y, f_val[0].z + f_val[1].z
    ],
    f_pos = f_off + rotate_pos([b, 0, 0], [finger_anchor_offset, -dy, -dz]),
    t_off = rotate_pos([d, 0, 0], [m_pcb_pad_size.x / 2, -thumb_anchor_offset, -dz]),
    t_pos = thumb_offset + rotate_pos(thumb_rotation, t_val[0] + t_off),
    diff = f_pos - t_pos,
    beta = atan((1 - cos(a)) / (sin(a) * cos(b))),
    r = (abs(diff.y) * sin(a) - abs(diff.x) * cos(a))
        / (cos(c) + sin(a - beta) * (1 - cos(a)) / sin(beta)),
    f = r * tan(a / 2),
    f_arc = f_pos + rotate_pos([b, 0, 0], [f * sin(a), -f * (1 + cos(a)), 0]),
    t_arc = thumb_offset
        + rotate_pos(thumb_rotation, t_val[0] + t_off + [r, r * cos(d), r * sin(d)]),
    // Approximate bending of the connector between thumb and finger cluster
    // with a bezier curve and calculate resulting length offset.
    // Bezier curve control points were empirically chosen to reduce curvature
    // while following the given constraints (see bending_approximation.py).
    bd = t_arc - f_arc,
    bx = sin(a) * bd.x - cos(a) * bd.y,
    bezier_points = [
        [0, 0],
        [bx / 2, 0],
        [bx - bx / 2 * cos(thumb_rotation.x + d),
            bd.z + bx / 2 * sin(thumb_rotation.x + d)],
        [bx, bd.z]
    ],
    bezier_len = bezier_curve_length(20, bezier_points),
    // 2D value calculations
    ps = m_pcb_pad_size,
    pos = m_pcb_vals[finger_anchor_index.x][finger_anchor_index.y] - [0, ps.y / 2],
    f_pos2 = [-pos.x + finger_anchor_offset, pos.y],
    f_arc2 = f_pos2 + [r * (1 - cos(a)), -r * sin(a)],
    t_pos2 = f_arc2 + rotate_pos([0, 0, a + 180], [r, bezier_len + r, 0]),
    t_off2 = t_pos2 + rotate_pos([0, 0, a + 180],
        m_pcb_thumb_vals[thumb_anchor_index] + [ps.x / 2, -thumb_anchor_offset, 0])
    ) [
        r, a, b, c, d,
        bezier_points, bezier_len,
        f_pos, t_pos, f_arc, f_val, t_val,
        f_pos2, f_arc2, t_pos2, t_off2
    ];


module flip_x(flip=true) {
    mirror([flip ? 1 : 0, 0, 0]) children();
}


module keycap(size) {
    color(keycap_color) scale([size, 1, 1]) rotate ([0, 0, 45])
        cylinder(keycap_size.z, d1 = keycap_size[0] * sqrt(2),
            d2 = keycap_size[1] * sqrt(2), $fn=4);
}


module switch() {
    color(switch_color) {
        rotate ([0, 0, 45])
            cylinder(switch_top_size.z, d1 = switch_top_size[0] * sqrt(2),
                d2 = switch_top_size[1] * sqrt(2), $fn=4);
        translate([0, 0, -switch_bottom_size[2] / 2])
            cube (switch_bottom_size, center=true);
    }
}


module key(size=1) {
    switch();
    translate([0, 0, switch_top_size.z]) keycap(size);
}


module keys() {
    if (show_keys && $preview) {
        flip_x() for (i = iter(finger_vals)) {
            vs = finger_vals[i];
            for (j = iter(vs)) {
                pos1 = vs[j][0];
                pos2 = vs[j][1];
                a1 = vs[j][2];
                a2 = vs[j][3];
                translate(pos1) rotate([0, a1, 0])
                    translate(pos2) rotate([a2, 0, 0]) key();
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


module interface_pcb() {
    if (show_pcb && $preview) {
        pos = mount_points[i_pcb_mount_point_index];
        x = -pos.x;
        y = pos.y - i_pcb_size.y / 2 - shell_thickness;
        z = i_pcb_size.z / 2;
        color(interface_pcb_color) translate([x, y, z] + i_pcb_offset)
            cube(i_pcb_size, center=true);
    }
}


module switch_cutout() {
    cube(switch_bottom_size + [0, 0, 2 * shell_thickness], center=true);
    translate([0, 0, -shell_thickness / 2 - plate_indent])
        cube([switch_bottom_size[0], switch_top_size[0], shell_thickness],
            center=true);
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
                translate(pos1) rotate([0, a1, 0])
                    translate(pos2) rotate([a2, 0, 0]) switch_cutout();
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
    h = shell_thickness + 2 * e;
    pos = mount_points[i_pcb_mount_point_index];
    x = -pos.x;
    y = pos.y - shell_thickness / 2;
    z = i_pcb_size.z;
    translate([x, y, z] + i_pcb_offset + port_offset) rotate([90, 0, 0]) if (left) {
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
        translate([0, 0, height]) rotate ([0, tenting_angle, 0])
            for (i = iter(finger_vals)) {
                vs = finger_vals[i];
                l = (i == 0) ? true : finger_vals[i - 1][s][0].z
                    >= finger_vals[i][0][0].z;
                r = (i == len(finger_vals) - 1) ? true : finger_vals[i][s][0].z
                    < finger_vals[i + 1][s][0].z;
                cl = (i == 0) ? 0 : finger_vals[i - 1][0][2] + finger_vals[i][0][2];
                cr = (i == len(finger_vals) - 1) ? 0 : finger_vals[i][0][2]
                    + finger_vals[i + 1][0][2];
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
                        + ((cdl != 0) ? cdl : (l ? d : 0))
                        + ((cdr != 0) ? cdr : (r ? d : 0));
                    mw = dy + md + ((j == 0 || j == len(vs) - 1) ? mount_rim.y : md);
                    mo = ((j == 0) ? (md - mount_rim.y) / 2
                        : (j == len(vs) - 1) ? (mount_rim.y - md) / 2 : 0);
                    translate(pos1) rotate([0, a1, 0])
                        translate(pos2) rotate([a2, 0, 0])
                            translate([o, mo, -mount_height / 2])
                                cube([ml, mw, mount_height], center=true);
                }
        }
        difference() {
            linear_extrude(mount_height) polygon(mount_points, mount_path, 10);
            for (i = [0, 1]) for (j = [0, 1]) {
                pos = mount_points[i * (len(mount_points) - 2) + j];
                d = sqrt(2) * finger_chamfer[2 * i + j];
                translate([pos.x, pos.y, mount_height / 2 - e])
                    rotate([0, 0, -45 + 90 * (i + j)])
                        cube([d + 10, d, mount_height], center=true);
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
            translate(thumb_offset) rotate(thumb_rotation)
                for (i = iter(thumb_vals)) {
                    v = thumb_vals[i];
                    pos = v[0];
                    a = v[1];
                    md = v[2];
                    w = dy + md + ((i == 0 || i == len(thumb_vals) - 1)
                        ? mount_rim.y : md);
                    mo = ((i == 0) ? (md - mount_rim.y) / 2
                        : (i == len(thumb_vals) - 1) ? (mount_rim.y - md) / 2 : 0);
                    translate(pos) rotate([a, 0, 0])
                        translate([0, mo, -mount_height / 2])
                            cube([l, w, mount_height], center=true);
                }
        difference() {
            translate([thumb_offset.x, thumb_offset.y, 0])
                rotate([0, 0, thumb_rotation.z]) difference() {
                    for (v = thumb_vals) {
                        pos = v[0];
                        x = pos.x;
                        y = pos.y + oy;
                        translate([x, y, mount_height / 2])
                            cube([ml, mw, mount_height], center=true);
                    }
                    for (i = [0, 1]) {
                        pos = thumb_vals[i * (len(thumb_vals) - 1)][0];
                        for (j = [0, 1]) {
                            d = sqrt(2) * thumb_chamfer[2 * i + j];
                            x = pos.x + sign(j - 0.5) * ml / 2;
                            y = pos.y + sign(i - 0.5) * mw / 2 + oy;
                            translate([x, y, mount_height / 2 - e])
                                rotate([0, 0, 45])
                                    cube([d, d, mount_height], center=true);
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
    t = max(shell_thickness, nut_rim[1]) + nut_width / 2;
    rotate([0, 0, angle]) translate([0, -t, 0]) difference() {
        union() {
            cylinder(h, d=w / cos(30), $fn=6);
            translate([-w / 2 / cos(30), 0, 0]) cube([w / cos(30), t, h]);
        }
        translate([0, 0, -e]) cylinder(nut_rim[0] + 2 * e, d=bolt_diameter);
        translate([0, 0, nut_rim[0]])
            cylinder(nut_height + e, d=nut_width / cos(30), $fn=6);
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
    translate([thumb_offset.x, dy, 0]) rotate([0, 0, thumb_rotation.z + 90])
        translate([0, l, 0]) nut_holder(0);
}


module i_pcb_holder() {
    l1 = 2;
    l2 = 10;
    h1 = i_pcb_offset.z;
    h2 = h1 + i_pcb_size.z;
    pos = mount_points[i_pcb_mount_point_index];
    x1 = -pos.x + i_pcb_offset.x;
    x2 = -mount_points[0].x;
    y1 = pos.y + l1 / 2 - shell_thickness + i_pcb_offset.y - i_pcb_size.y;
    y2 = pos.y - i_pcb_size.y - shell_thickness + i_pcb_offset.y - l2 / 2;
    w1 = i_pcb_size.x / 3;
    w2 = x2 - x1 + w1 / 2;
    translate([x1, y1, h1 / 2]) cube([w1, l1 + 2 * e, h1], center=true);
    translate([x2 - w2 / 2, y2, h2 / 2]) cube([w2, l2, h2], center=true);
}


module mount(left=true) {
    translate([(left ? -40 : 40), 0, 0]) flip_x(!left) {
        difference() {
            // main body
            union() {
                shell(shell_thickness, shell_fn) {
                    finger_cluster();
                    thumb_cluster();
                }
                nut_holders();
                i_pcb_holder();
            }
            // cutouts
            switch_cutouts();
            port_cutouts(left);
        }
        // preview elements
        interface_pcb();
        translate([0, 0, height]) rotate ([0, -tenting_angle, 0]) {
            keys();
            thumb_connector_visualisation();
        }
    }
}


module shell(t, fn) {
    if (calculate_shell || !$preview) {
        render(10) intersection() {
            children();
            minkowski() {
                difference() {
                    translate([0, 0, 500]) cube([1000, 1000, 1000], center=true);
                    children();
                }
                sphere(r=t, $fn=fn);
            }
        }
    }
    else {
        children();
    }
}


module case() {
    // left half
    mount(left=true);
    // right half
    mount(left=false);
}


module m_pcb_pad_with_connector(conn_l, conn_x, conn_y) {
    difference() {
        union() {
            square(m_pcb_pad_size, center=true);
            translate([conn_x, conn_y]) {
                square([m_pcb_straight_conn_width, conn_l]);
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


module connector(m_pcb_pos, m_pcb_ppos, w, left=true) {
    pos1 = ((left) ? m_pcb_pos : m_pcb_ppos)
        + [((left) ? -1 : 1) * m_pcb_pad_size.x / 2, m_pcb_pad_size.y / 2 - w / 2];
    pos2 = ((left) ? m_pcb_ppos : m_pcb_pos)
        + [((left) ? 1 : -1) * (m_pcb_pad_size.x / 2 - w / 2), -m_pcb_pad_size.y / 2];
    r = abs(pos1.x - pos2.x) / 3;
    l = abs(pos2.y - pos1.y) - r;
    translate(pos1) flip_x(left) {
        translate([0, -r]) arc(r, w);
        translate([r, -r - l]) line(l, w);
        translate([2 * r, -r - l]) rotate(-90) arc(r, w, 180);
    }
}


module thumb_connector_visualisation() {
    if (visualize_bending && $preview) {
        r = thumb_connector_vals[0];
        a = thumb_connector_vals[1];
        b = thumb_connector_vals[2];
        c = thumb_connector_vals[3];
        d = thumb_connector_vals[4];
        bezier_points = thumb_connector_vals[5];
        bezier_len = thumb_connector_vals[6];
        f_pos = thumb_connector_vals[7];
        t_pos = thumb_connector_vals[8];
        f_arc = thumb_connector_vals[9];
        f_val = thumb_connector_vals[10];
        t_val = thumb_connector_vals[11];

        color(matrix_pcb_color) {
            // arcs
            translate(f_pos) rotate([b, 0, 0]) rotate(90)
                translate([0, -r, -m_pcb_thickness]) flip_x()
                    linear_extrude(m_pcb_thickness) arc(r, 3, a);
            translate(t_pos) rotate(thumb_rotation + [d, 0, 0]) rotate(-90)
                    translate([-r, 0, -m_pcb_thickness])
                        linear_extrude(m_pcb_thickness) arc(r, 3);
            // bending part of the connector approximated with a bezier curve
            translate(f_arc) rotate(a - 90) {
                seg_size = 2 * bezier_len / bending_visualisation_segs;
                for (t = [0 : 1 / bending_visualisation_segs : 1]) {
                    pos = bezier_point(t, bezier_points);
                    angle = (-c - b) * t + b;
                    translate([pos[0], 0, pos[1]]) rotate([angle, 0])
                    translate([0, 0, -m_pcb_thickness / 2])
                        cube([seg_size, thumb_connector_width, m_pcb_thickness],
                            center=true);
                }
            }
        }

        // keys
        flip_x() translate(f_val[0]) rotate([0, f_val[2], 0])
            translate(f_val[1]) rotate([f_val[3], 0, 0]) key();
        translate(thumb_offset) rotate(thumb_rotation)
            translate(t_val[0]) rotate([t_val[1], 0, 0]) key(1.5);
    }
}


module matrix_pcb_outline() {
    // finger cluster
    flip_x() for (i = iter(finger_vals)) {
        vs = finger_vals[i];
        ps = m_pcb_vals[i];
        s = -col_range[0];
        if (i > 0) {
            a = finger_vals[i - 1][0][2] + finger_vals[i][0][2];
            if (a != 0) {
                conn_l = ps[s].x - m_pcb_vals[i - 1][s].x - m_pcb_pad_size.x + 2 * e;
                conn_x = -m_pcb_pad_size.x / 2 + e;
                translate(m_pcb_vals[i-1][s]
                    - [conn_x, m_pcb_straight_conn_width / 2])
                        square([conn_l, m_pcb_straight_conn_width]);
            }
            else {
                left = finger_vals[i - 1][s][0].z >= finger_vals[i][s][0].z;
                connector(ps[s], m_pcb_vals[i - 1][s], m_pcb_connector_width, left);
            }
        }
        for (j = iter(vs)) {
            v = vs[j];
            pos1 = v[0];
            pos2 = v[1];
            a1 = v[2];
            a2 = v[3];
            m_pcb_pos = ps[j];
            m_pcb_ppos = ps[max(j - 1, 0)];
            conn_l = m_pcb_pos.y - m_pcb_ppos.y - m_pcb_pad_size.y + 2 * e;
            conn_x = (-m_pcb_straight_conn_width + m_pcb_ppos.x - m_pcb_pos.x) / 2;
            conn_y = -conn_l - m_pcb_pad_size.y / 2 + e;
            translate(m_pcb_pos) m_pcb_pad_with_connector(conn_l, conn_x, conn_y);
        }
    }
    // thumb connector
    w = thumb_connector_width;
    r = thumb_connector_vals[0];
    a = thumb_connector_vals[1];
    conn_l = thumb_connector_vals[6];
    f_pos = thumb_connector_vals[12];
    f_arc = thumb_connector_vals[13];
    t_pos = thumb_connector_vals[14];
    t_off = thumb_connector_vals[15];
    translate(f_pos) rotate(90) translate([0, -r]) flip_x() arc(r, w, a);
    translate(f_arc) rotate(a + 180) line(conn_l, w);
    translate(t_pos) rotate(a + 180) translate([0, -r]) flip_x() arc(r, w);
    // thumb cluster
    translate(t_off) rotate(a)
    for (i = iter(m_pcb_thumb_vals)) {
        pos = m_pcb_thumb_vals[i];
        ppos = m_pcb_thumb_vals[max(i - 1, 0)];
        conn_l = pos.y - ppos.y - m_pcb_pad_size.y + 2 * e;
        conn_x = -m_pcb_straight_conn_width / 2;
        conn_y = -conn_l - m_pcb_pad_size.y / 2 + e;
        translate(pos) m_pcb_pad_with_connector(conn_l, conn_x, conn_y);
    }
}


// build case
if (build_case) {
    case();
}
// show preview of the matrix pcb
else if ($preview) {
    color(matrix_pcb_color) linear_extrude(m_pcb_thickness)
    matrix_pcb_outline();
    translate([0, 0, -thumb_connector_vals[8].z + switch_bottom_size.x / 2])
        thumb_connector_visualisation();
}
// 2D render version of the matrix pcb outline
else {
    // output different values for automatic pcb generation
    echo(-m_pcb_vals, -thumb_rotation.z, thumb_connector_vals[15], m_pcb_thumb_vals);
    matrix_pcb_outline();
}
