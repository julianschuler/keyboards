/* [Preview settings] */
// show the keys during preview
show_keys = true;

// show the interface PCB during preview
show_interface_pcb = true;

// show a visualisation of the bending of the PCB thumb connector
visualize_bending = true;
// number of segments used to visualize the bending connector
bending_visualisation_segs = 50;

// show the bottom plate during preview
show_bottom_plate = false;

// render parts during preview, preview will take longer but is more responsive
render_preview = false;

// calculate the shell during preview, preview will take much longer
calculate_shell = false;


/* [Key cluster settings] */
// amount of rows, automatic PCB generation is supported for 1 to 5 rows
row_count = 4; // [1, 2, 3, 4, 5]
// amount of columns, automatic PCB generation is supported for 2 to 6 columns
column_count = 6; // [2, 3, 4, 5, 6]
// amount of thumb keys, automatic PCB generation is supported for 1 to 6 keys
thumb_key_count = 3; // [1, 2, 3, 4, 5, 6]

// row index of the home row (usually 1)
home_row_index = 1; // [0, 1, 2, 3, 4]
// index of the thumb key the hand is naturally resting on (usually the center key)
thumb_default_index = 1; // [0, 1, 2, 3, 4, 5]

// distance between neighbouring keys
key_distance = [19.05, 19.05];

// finger column side rotation for the left- and rightmost columns
finger_rotation = [15, 15];
// finger column curvature as angle between two neighbouring keys, per column
finger_angles = [20, 20, 20, 20, 20, 20];
// finger column Y and Z offsets relative to the first column offset, per column
finger_offset = [
    [0, 0], [0, 0], [0, -3], [0, 0], [-20, 5], [-20, 5]
];

// thumb well curvature as angle between two neighbouring keys
thumb_angle = 15;
// rotation of the thumb cluster in relation to the finger cluster
thumb_rotation = [30, 15, 80];
// offset of the thumb cluster to the finger cluster
thumb_offset = [-3.05, -48, 10];


/* [Keyboard settings] */
// thickness of the keyboard shell
shell_thickness = 2.1;

// thickness of the bottom plate
bottom_plate_thickness = 1.6;

// depths of the chamfers in the corners of the finger cluster
finger_chamfers = [0, 5.5, 12, 9];
// depths of the chamfers in the corners of the thumb cluster
thumb_chamfer = [5, 7, 10, 7];

// extra material added around the finger cluster
finger_rim = [1, 4];
// extra material added around the thumb cluster
thumb_rim = [2, 4];
// width of the extra inner material used for the finger cluster rim
finger_rim_inner = 3;
// minimum clearance between the finger cluster and thumb cluster
finger_clearance = 1.5;

// width of the extra inner material used for the thumb cluster rim
thumb_rim_offset = 0;
// width of the extra material extending the thumb cluster to the top
thumb_rim_top_offset = 2;

// keyboard tilting angle along X and Y
tilting_angle = [15, -20];

// value the cluster is offset along the Z axis to create a valid keyboard
height_offset = 43;

// value each half is offset along the X axis
half_offset = 40;

// polygon indices to add the nut holders to, format: [i, rotation, offset]
nut_values = [[5, 0, 7], [11, 0, 5.5], [8, 180, 7]];

// finger indices to add extra width to, format: [col, row, extra_width_amount]
extra_widths = [[4, 0, -19.05], [3, 2, 38.1], [3, 3, 38.1]];

// anchor point of the thumb connector, select to minimize bending
thumb_anchor_index = 0; // [0, 1, 2, 3, 4, 5]

// value greater than the total keyboard height, used for intersections and co.
safe_height = 100;


/* [Colors] */
keycap_color = "#333333";
switch_color = "#E6E6E6";
matrix_pcb_color = "#008C4A";
interface_pcb_color = "#6C0D5D";
fpc_connector_color = "#8F8F8F";


/* [Rendering and export options] */
// build key matrix PCB instead of the keyboard
build_matrix_pcb = false;
// adjust only if the shell calculation fails, small values are recommended
shell_fn = 15;
// minium angle, sensible default for 3D printing
$fa = 3;
// minimum segment size, sensible default for 3D printing
$fs = 0.01;

// don't show the following values in the customizer
module __Customizer_Limit__() {}

// epsilon used in differences and intersections (shouldn't be changed)
e = 0.01;

// key matrix PCB values (shouldn't be changed)
m_pcb_col_connector_width = 2;
m_pcb_straight_conn_width = 2.5;
m_pcb_pad_size = [13, 14];
m_pcb_thickness = 0.6;
m_pcb_router_diameter = 2;

// fpc connector values (shouldn't be changed)
fpc_index = 1;
fpc_pad_size = [19, 4];
fpc_offset = [0, 7.9];
fpc_connector_size = [19, 5.3, 2.5];
fpc_connector_offset = [0, 1.8];

// thumb connector values (shouldn't be changed)
finger_anchor_offset = 0;
thumb_anchor_offset = 0;
thumb_connector_width = 2.3;

// nut and bolt values (shouldn't be changed)
bolt_diameter = 3.2;
bolt_head_height = 1.86;
bolt_length = 8;
nut_width = 5.5;
nut_height = 2.8;
nut_rim = [1.5, 2];

// keycap and switch values (shouldn't be changed)
keycap_size = [18.4, 12.3, 7.7];
switch_top_size = [15.6, 10, 6.6];
switch_bottom_size = [14, 14, 5];
plate_indent = 1.5;

// interface PCB values (shouldn't be changed)
i_pcb_size = [36, 42, 1.6];
i_pcb_offset = [-2.2, -0.2, 2];
i_pcb_mount_point_index = 3;
i_pcb_mounting_hole_diameter = 2.2;
i_pcb_mounting_hole_offset = 3;
i_pcb_mounting_hole_clearance = 0.1;
i_pcb_holder_width = 8;
i_pcb_holder_thickness = 2;
i_pcb_holder_clearance = 0.2;

// port values (shouldn't be changed)
usb_width = 9.2;
usb_height = 3.4;
usb_radius = 1.1;
usb_offset = 19.5;
jack_radius = 3.1;
jack_offset = [5.3, 0.55];
port_offset = [7.3, 0, 1.7];
kb2040_pcb_thickness = 1.6;

// build matrix PCB outline instead of the keyboard (will be overwritten externally)
build_matrix_pcb_outline = false;
// bottom plate settings (shouldn't be changed, will be overwritten by export script)
build_bottom_plate = false;
build_bottom_plate_outline = false;


// assertions to ensure the validity of the input
assert(len(finger_angles) >= column_count,
    "Finger well angle list has to have at least as many entries as columns."
);
assert(len(finger_offset) >= column_count,
    "Finger column offset list has to have at least as many entries as columns."
);
for (i = iter(finger_angles)) {
    assert(finger_angles[i] > 0, "Finger well angles have to be greater 0.");
}
assert(thumb_angle > 0, "Thumb well angle has to be greater than 0.");
assert(home_row_index >= 0 && home_row_index < row_count,
    "Home row index has to select an existing row."
);
assert(thumb_default_index >= 0 && thumb_default_index < thumb_key_count,
    "Thumb default index has to select an existing thumb key."
);
assert(thumb_anchor_index >= 0 && thumb_anchor_index < thumb_key_count,
    "Thumb anchor index has to select an existing thumb key."
);


// helper function for creating a list from 0 to end - 1
function range(end) = [0 : end - 1];

// helper function for creating indices for iterating a list
function iter(list) = range(len(list));

// function for calculing the sum of a list
function sum(list, s=0, i=0) = (i == len(list)) ? s : sum(list, s + list[i], i + 1);

// function for calculating the projection of a vector v onto the plane given
// by the normal vector n
function proj(v, n) = v - ((v * n) / (n * n)) * n;

// function for rotating a vector
function rotate_vec(angles, pos) = let(
    sx = sin(angles.x),
    sy = sin(angles.y),
    sz = (len(angles) == 3) ? sin(angles.z) : 0,
    cx = cos(angles.x),
    cy = cos(angles.y),
    cz = (len(angles) == 3) ? cos(angles.z) : 1,
    R = [ [cz * cy,    cz * sy * sx - sz * cx,    cz * sy * cx + sz * sx],
          [sz * cy,    sz * sy * sx + cz * cx,    sz * sy * cx - cz * sx],
          [-sy,        cy * sx,                   cy * cx               ] ]
)
    R * pos;

// function for performing a linear interpolation between two points
// with 0 <= t <= 1, lerp(0, p0, p1) = p0 and lerp(1, p0, p1) = p1
function lerp(t, p0, p1) = (p1 - p0) * t + p0;

// function for calculating a point on a bezier curve given by t with
// 0 <= t <= 1 and the list of control points p = [p0, p1, p2, p3]
function bezier_point(t, p) = let (
    p4 = lerp(t, p[0], p[1]),
    p5 = lerp(t, p[1], p[2]),
    p6 = lerp(t, p[2], p[3]),
    p7 = lerp(t, p4, p5),
    p8 = lerp(t, p5, p6)
)
    lerp(t, p7, p8);

// function for calculating a vector tangent to a bezier curve at the
// point given by bezier_point(t, p)
function bezier_tangent(t, p) = let (t2 = t * t)
    p[0] * ( -3 * t2 +  6 * t - 3 ) +
    p[1] * (  9 * t2 - 12 * t + 3 ) +
    p[2] * ( -9 * t2 +  6 * t     ) +
    p[3] * (  3 * t2              );

// function for approximate the length of a bezier curve given by the list of
// control points p = [p0, p1, p2, p3] using a given number of steps
function bezier_curve_length(steps, p) = let (step_size = 1 / steps)
    sum([for (t = [0 : step_size : 1 - step_size]) let (
        p4 = bezier_point(t, p),
        p5 = bezier_point(t + step_size, p)
    )
        norm(p5 - p4)
    ]);

// helper function for retrieving the extra width for a given i and j
function extra_width(i, j) = [ for (e = extra_widths)
    if (e[0] == i && e[1] == j) e[2], 0
][0];


finger_vals = [ for (i = range(column_count)) let (
    h = switch_top_size.z,
    dx = key_distance.x,
    dy = key_distance.y,
    a1 = (i == 0) ? finger_rotation[0]
        : ((i == column_count - 1) ? -finger_rotation[1] : 0),
    a2 = finger_angles[i],
    c1 = (a1 == 0) ? 0 : dx / 2 / tan(abs(a1 / 2)),
    c2 = (a2 == 0) ? 0 : dy / 2 / tan(a2 / 2),
    r1 = c1 + h,
    r2 = c2 + h,
    x1 = dx * (i + sign(a1)) - r1 * sin(a1),
    z1 = r1 * (1 - cos(a1)),
    off = finger_offset[i] - finger_offset[0],
    md = (h + safe_height) * tan(a2 / 2)
) [ for (j = range(row_count)) let (
        b2 = a2 * (j - home_row_index),
        y2 = r2 * sin(b2),
        cs = (1 - cos(b2)),
        z2 = r2 * cs,
        x2 = -tan(a1) * (c2 * cs + dy / 2 * sin(abs(b2)))
    )
        [[x1, off[0], z1 + off[1]], [x2, y2, z2], a1, b2, md]
    ]
];

thumb_vals = [ for (i = range(thumb_key_count)) let (
    h = switch_top_size.z,
    dx = key_distance.x,
    dy = key_distance.y,
    a2 = thumb_angle,
    c2 = (a2 == 0) ? 0 : dy / 2 / tan(a2 / 2),
    r2 = c2 + h,
    md = (h + safe_height) * tan(a2 / 2),
    b2 = a2 * (i - thumb_default_index),
    y2 = r2 * sin(b2),
    z2 = r2 * (1 - cos(b2))
)
    [[0, y2, z2], b2, md]
];

mount_points = [ for (i = range(column_count + 1)) let (
    l = len(finger_vals),
    dx = key_distance.x / 2 + finger_rim.x,
    dy = key_distance.y / 2 + finger_rim.y,
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
    ym = max(posm1.y, pposm1.y) + max(posm2.y, pposm2.y) + dy,
    x = (i == l) ? max(x0, xm) : min(x0, xm)
) each [
    [x, y0], [x, ym]]
];

mount_path = [[
    each [0 : 2 : 2 * (len(finger_vals))],
    each [2 * len(finger_vals) + 1 : -2 : 1]
]];

thumb_mount_points = let(
    dx = key_distance.x * 0.75 + thumb_rim.x,
    dy = key_distance.y / 2 + thumb_rim.y,
    to = thumb_rim_top_offset,
    t_pos0 = thumb_vals[0][0],
    t_posm = thumb_vals[len(thumb_vals) - 1][0],
    pos01 = rotate_vec(tilting_angle,
        rotate_vec(thumb_rotation, t_pos0 + [-dx, -dy, 0]) + thumb_offset),
    pos02 = rotate_vec(tilting_angle,
        rotate_vec(thumb_rotation, t_pos0 + [dx + to, -dy, 0]) + thumb_offset),
    posm1 = rotate_vec(tilting_angle,
        rotate_vec(thumb_rotation, t_posm + [-dx, dy, 0]) + thumb_offset),
    posm2 = rotate_vec(tilting_angle,
        rotate_vec(thumb_rotation, t_posm + [dx + to, dy, 0]) + thumb_offset)
    ) [
        [pos01.x, pos01.y], [pos02.x, pos02.y], [posm2.x, posm2.y], [posm1.x, posm1.y]
    ];

m_pcb_vals = [ for (i = iter(finger_vals))
    let (
        h = switch_top_size.z + switch_bottom_size.z,
        vs = finger_vals[i],
        kx = key_distance.x,
        ky = key_distance.y,
        sy = m_pcb_pad_size.y,
        sx = m_pcb_pad_size.x,
        a1 = (i == 0) ? finger_rotation[0]
            : ((i == column_count - 1) ? -finger_rotation[1] : 0),
        a2 = finger_angles[i],
        c1 = (a1 == 0) ? 0 : (kx - sx) / 2 / tan(abs(a1 / 2)),
        r1 = c1 + h,
        dx = -(sx + (PI * r1 * abs(a1) / 180)) * sign(a1) + kx * (i + sign(a1))
    ) [ for (j = iter(vs))
        let (
            v = vs[j],
            pos1 = v[0],
            pos2 = v[1],
            c2 = (a2 == 0) ? 0 : (ky - sy) / 2 / tan(abs(a2 / 2)),
            r2 = c2 + h,
            dy = (sy + (PI * r2 * abs(a2) / 180)) * (j - home_row_index)
        )
            [dx + pos2.x, dy + pos1.y, 0]
    ]
];

m_pcb_thumb_vals = [ for (i = iter(thumb_vals))
    let (
        h = switch_top_size.z + switch_bottom_size.z,
        ky = key_distance.y,
        sy = m_pcb_pad_size.y,
        sx = m_pcb_pad_size.x,
        a = thumb_angle,
        r = (a == 0) ? 0 : (ky - sy) / 2 / tan(abs(a / 2)) + h,
        dy = (sy + (PI * r * a / 180)) * (i - thumb_default_index)
    )
        [0, dy, 0]
];

col_connector_vals = [ for (i = iter(m_pcb_vals))
    if (i > 0) let(
        s = home_row_index,
        w = m_pcb_col_connector_width,
        a = finger_vals[i - 1][s][2] + finger_vals[i][s][2],
        m_pcb_pos = m_pcb_vals[i][s],
        m_pcb_ppos = m_pcb_vals[i - 1][s]
    )
    if (a != 0) let(
        // straight connector vals
        pos1 = m_pcb_pos - [m_pcb_pad_size.x / 2, 0],
        pos2 = m_pcb_ppos + [m_pcb_pad_size.x / 2, 0]
    )
        [2, pos1, pos2]
    else let(
        // curved connector vals
        pfv = finger_vals[i - 1][s][0],
        fv = finger_vals[i][s][0],
        left = (pfv.y < fv.y || (pfv.y == fv.y && pfv.z > fv.z)),
        pos1 = ((left) ? m_pcb_pos : m_pcb_ppos)
            + [((left) ? -1 : 1) * m_pcb_pad_size.x / 2, m_pcb_pad_size.y / 2 - w / 2],
        pos2 = ((left) ? m_pcb_ppos : m_pcb_pos)
            + [((left) ? 1 : -1) * (m_pcb_pad_size.x / 2), -m_pcb_pad_size.y / 2 + w / 2]
    )
        [left ? 1 : 0, pos1, pos2]
];

thumb_connector_vals = let(
    // values for connector endpoints
    f_val = finger_vals[fpc_index][0],
    t_val = thumb_vals[thumb_anchor_index],
    // angles
    alpha = f_val[3],
    beta = t_val[1],
    // value calculations
    dx = m_pcb_pad_size.x / 2,
    dy = fpc_offset.y + fpc_pad_size.y / 2,
    dz = switch_bottom_size.z,
    f_off = [
        -f_val[0].x - f_val[1].x, f_val[0].y + f_val[1].y, f_val[0].z + f_val[1].z
    ],
    f_pos = f_off + rotate_vec([alpha, 0], [finger_anchor_offset, -dy, -dz]),
    t_off = rotate_vec([beta, 0], [dx, -thumb_anchor_offset, -dz]),
    t_pos = thumb_offset + rotate_vec(thumb_rotation, t_val[0] + t_off),
    diff = f_pos - t_pos,
    // normal vectors for planes parallel to the finger and thumb key
    n_f = rotate_vec([alpha, 0], [0, 0, 1]),
    n_t = rotate_vec(thumb_rotation, rotate_vec([beta, 0], [0, 0, 1])),
    // vector along the thumb key plane
    v_t = rotate_vec(thumb_rotation, rotate_vec([beta, 0], [0, 1, 0])),
    // plane to project on, given by the average normal vector of both planes
    n_a = n_f + n_t,
    // normal vector for the plane going through v_t and n_a
    n_p = cross(v_t, n_a),
    // vector along the intersection of the planes given by n_p and n_f
    v_i = cross(n_p, n_f),
    v_n = v_i / norm(v_i),
    // calculate arc angle
    b = rotate_vec([alpha, 0], [0, 1, 0]),
    phi = 180 - acos(b * v_n),
    // calculate radius
    b_a = proj(b, n_a),
    c = rotate_vec(thumb_rotation, rotate_vec([beta, 0], [1, 0, 0])),
    c_a = proj(c, n_a),
    d = b_a * tan(phi / 2) + c_a,
    r = (diff * n_p) / (d * n_p),
    // calculate end points of the arc segments
    f_arc = f_pos + r * tan(phi / 2) * (v_n - b),
    t_arc = t_pos + r * (c + v_t),
    // Approximate bending of the connector between thumb and finger cluster
    // with a cubic bezier curve and calculate resulting length offset.
    // Bezier curve control points were empirically chosen to reduce curvature
    // while following the given constraints (see bending-approximation.py).
    diff_b = t_arc - f_arc,
    len_b = norm(proj(diff_b, n_a)) / 2,
    bezier_points = [
        f_arc,
        f_arc + len_b * v_n,
        t_arc + len_b * v_t,
        t_arc,
    ],
    bezier_len = bezier_curve_length(20, bezier_points),
    // 2D value calculations
    pos_2d = m_pcb_vals[fpc_index][0] - [0, dy],
    f_pos_2d = [-pos_2d.x + finger_anchor_offset, pos_2d.y],
    f_arc_2d = f_pos_2d + [r * (1 - cos(phi)), -r * sin(phi)],
    t_pos_2d = f_arc_2d + rotate_vec([0, 0, phi], [-r, -bezier_len - r, 0]),
    t_off_2d = t_pos_2d + rotate_vec([0, 0, phi + 180],
        m_pcb_thumb_vals[thumb_anchor_index] + [dx, -thumb_anchor_offset, 0])
) [
    r, phi, bezier_points,
    f_pos, t_pos, f_val, t_val, n_f, n_t,
    bezier_len, f_pos_2d, f_arc_2d, t_pos_2d, t_off_2d
];

bezier_visualisation_vertices = let(
    bezier_points = thumb_connector_vals[2],
    n_f = thumb_connector_vals[7],
    n_t = thumb_connector_vals[8]
) [ for (t = [0 : 1 / bending_visualisation_segs : 1])
    let(
        pos = bezier_point(t, bezier_points),
        tangent = bezier_tangent(t, bezier_points),
        n = lerp(t, n_f, n_t),
        v = cross(n, tangent),
        u = cross(v, tangent),
        w = v / norm(v) * thumb_connector_width / 2,
        h = u / norm(u) * m_pcb_thickness
    ) each [
        pos + w, pos - w, pos - w + h, pos + w + h
    ]
];

bezier_visualisation_faces = let(m = 4 * bending_visualisation_segs) [
    each [ for (i = [0 : 4 : m - 1])
        each [
            [i,     i + 1, i + 5, i + 4],
            [i + 1, i + 2, i + 6, i + 5],
            [i + 2, i + 3, i + 7, i + 6],
            [i + 3, i    , i + 4, i + 7],
        ]
    ],
    each [
        [0, 1, 2, 3 ],
        [m, m + 1, m + 2, m + 3]
    ]
];


module debug_vector(v, pos=[0, 0, 0], dv=0.2, dt=0.6, ht=0.6, fn=12) {
    n = norm(v);
    v_n = v / n;
    I = [ [1, 0, 0],
          [0, 1, 0],
          [0, 0, 1] ];
    A = [ [0,      0,      v_n.x],
          [0,      0,      v_n.y],
          [-v_n.x, -v_n.y, 0    ] ];

    R = I + A + 1 / (1 + v_n.z) * (A * A);

    color("red") translate(pos) multmatrix(R) {
        cylinder(d=dv, h=n - ht, $fn=fn);
        translate([0, 0, n - ht]) cylinder(d1=dt, d2=0, h=ht, $fn=fn);
    }
}

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
                translate(pos1) rotate([0, a1])
                    translate(pos2) rotate([a2, 0]) key();
            }
        }
        translate(thumb_offset) rotate(thumb_rotation) for (v = thumb_vals) {
            pos = v[0];
            a = v[1];
            pw = v[2];
            translate(pos) rotate([a, 0]) key(1.5);
        }
    }
}


module interface_pcb() {
    if (show_interface_pcb && $preview) {
        pos = mount_points[i_pcb_mount_point_index];
        x = -pos.x;
        y = pos.y - i_pcb_size.y / 2 - shell_thickness;
        z = i_pcb_size.z / 2;
        d = i_pcb_mounting_hole_diameter;
        o = i_pcb_mounting_hole_offset;
        h = i_pcb_size.z + 2 * e;
        fy = fpc_connector_offset.y;
        translate([x, y, z] + i_pcb_offset) {
            color(interface_pcb_color) difference() {
                cube(i_pcb_size, center=true);
                translate([i_pcb_size.x / 2 - o, -i_pcb_size.y / 2 + o])
                    cylinder(d=d, h=h, center=true);
                translate([-i_pcb_size.x / 2 + o, -i_pcb_size.y / 2 + o])
                    cylinder(d=d, h=h, center=true);
            }
            translate([0, -i_pcb_size.y / 2 + fy, i_pcb_size.z / 2])
                fpc_connector();
        }
    }
}


module fpc_connector() {
    color(fpc_connector_color)
        translate([-fpc_connector_size.x / 2, 0] - fpc_connector_offset)
            cube(fpc_connector_size);
}


module switch_cutout() {
    cube(switch_bottom_size + [0, 0, 2 * shell_thickness], center=true);
    translate([0, 0, -shell_thickness / 2 - plate_indent])
        cube([switch_bottom_size[0], switch_top_size[0], shell_thickness],
            center=true);
}


module switch_cutouts() {
    translate([0, 0, height_offset]) rotate (tilting_angle) {
        flip_x() for (i = iter(finger_vals)) {
            vs = finger_vals[i];
            for (j = iter(vs)) {
                pos1 = vs[j][0];
                pos2 = vs[j][1];
                a1 = vs[j][2];
                a2 = vs[j][3];
                translate(pos1) rotate([0, a1])
                    translate(pos2) rotate([a2, 0]) switch_cutout();
            }
        }
        translate(thumb_offset) rotate(thumb_rotation) for (v = thumb_vals) {
            pos = v[0];
            a = v[1];
            translate(pos) rotate([a, 0]) switch_cutout();
        }
    }
}


module port_cutouts(left=true) {
    w = usb_width;
    l = usb_height;
    r = usb_radius;
    o = usb_offset;
    uz = kb2040_pcb_thickness;
    jr = jack_radius;
    jo = jack_offset;
    h = shell_thickness + 2 * e;
    pos = mount_points[i_pcb_mount_point_index];
    x = -pos.x;
    y = pos.y - shell_thickness / 2 - i_pcb_offset.y;
    z = i_pcb_size.z;
    translate([x, y, z] + i_pcb_offset + port_offset) rotate([90, 0]) if (left) {
        translate([jo[0] - o, uz, 0]) minkowski() {
            cube([w - 2 * r, l - 2 * r, h - e], center=true);
            cylinder(e, r=r, center=true);
        }
        translate(jo) cylinder(h, r=jr, center=true);
    }
    else {
        translate([0, jo.y, 0]) cylinder(h, r=jr, center=true);
    }
}


module bolt_cutout() {
    h = bolt_head_height;
    d = bolt_diameter;
    cylinder(d=d, h=bolt_length);
    translate([0, 0, -e]) cylinder(d1=d + 2 * h + 2 * e, d2=d, h=h + e);
}


module finger_cluster() {
    w = keycap_size.x / 2 - switch_bottom_size.x / 2;
    d = key_distance.x - keycap_size.x + e;
    dy = key_distance.y;
    h = switch_top_size.z;
    s = home_row_index;
    flip_x() intersection() {
        translate([0, 0, height_offset]) rotate([tilting_angle.x, -tilting_angle.y])
            for (i = iter(finger_vals)) {
                vs = finger_vals[i];
                l = (i == 0) ? true : finger_vals[i - 1][s][0].z
                    >= finger_vals[i][0][0].z;
                r = (i == len(finger_vals) - 1) ? true : finger_vals[i][s][0].z
                    < finger_vals[i + 1][s][0].z;
                cl = (i == 0) ? 0 : finger_vals[i - 1][0][2] + finger_vals[i][0][2];
                cr = (i == len(finger_vals) - 1) ? 0 : finger_vals[i][0][2]
                    + finger_vals[i + 1][0][2];
                cdl = (h + safe_height) * tan(abs(cl / 2));
                cdr = (h + safe_height) * tan(abs(cr / 2));
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
                    mw = dy + md
                        + ((j == 0 || j == len(vs) - 1) ? finger_rim_inner : md);
                    mo = ((j == 0) ? (md - finger_rim_inner) / 2
                        : (j == len(vs) - 1) ? (finger_rim_inner - md) / 2 : 0);
                    translate(pos1) rotate([0, a1])
                        translate(pos2) rotate([a2, 0])
                            translate([o, mo, -safe_height / 2])
                                cube([ml, mw, safe_height], center=true);
                }
        }
        difference() {
            linear_extrude(safe_height) polygon(mount_points, mount_path, 10);
            for (i = [0, 1]) for (j = [0, 1]) {
                pos = mount_points[i * (len(mount_points) - 2) + j];
                d = sqrt(2) * finger_chamfers[2 * i + j];
                translate([pos.x, pos.y, safe_height / 2 - e])
                    rotate(-45 + 90 * (i + j))
                        cube([2 * d, d, safe_height], center=true);
            }
        }
    }
}


module thumb_cluster() {
    dy = key_distance.y / 2;
    my = keycap_size.y / 2 + thumb_rim_offset;
    intersection() {
        translate([0, 0, height_offset]) rotate (tilting_angle)
            translate(thumb_offset) rotate(thumb_rotation)
                for (i = iter(thumb_vals)) {
                    v = thumb_vals[i];
                    pos = v[0];
                    a = v[1];
                    md = v[2];
                    w = dy + md + ((i == 0 || i == len(thumb_vals) - 1) ? my : md);
                    mo = ((i == 0) ? (md - my) / 2
                        : (i == len(thumb_vals) - 1) ? (my - md) / 2 : 0);
                    translate(pos) rotate([a, 0])
                        translate([0, mo, -safe_height / 2])
                            cube([safe_height, w, safe_height], center=true);
                }
        difference() {
            linear_extrude(safe_height) polygon(thumb_mount_points, convexity=10);
            m = len(thumb_mount_points);
            mp = thumb_mount_points;
            for (i = iter(mp)) {
                pos = mp[i];
                d = sqrt(2) * thumb_chamfer[i];
                dv1 = mp[(i + 1) % m] - pos;
                dv2 = mp[(i + m - 1) % m] - pos;
                dv = dv1 / norm(dv1) + dv2 / norm(dv2);
                a = atan2(-dv.x, dv.y);
                translate([pos.x, pos.y, safe_height / 2 - e])
                    rotate(a) cube([2 * d, d, safe_height], center=true);
            }
            flip_x() linear_extrude(safe_height)
                offset(delta=finger_clearance - finger_rim.y)
                    polygon(mount_points, mount_path, convexity=10);
        }
    }
}


module bottom_plate() {
    t = max(shell_thickness, nut_rim[1]) + nut_width / 2;
    v1 = thumb_mount_points[0];
    v2 = thumb_mount_points[3];
    dv = (v2 - v1) / 2;
    a = atan2(-dv.x, dv.y);
    difference() {
        linear_extrude(bottom_plate_thickness) projection(cut=true) {
            finger_cluster();
            thumb_cluster();
        }
        flip_x() for (v = nut_values) {
            pos = mount_points[v[0]] + [v[2], 0];
            translate(pos) rotate(v[1]) translate([0, -t]) bolt_cutout();
        }
        translate(v1 + dv) rotate(a) translate([t, 0]) bolt_cutout();
    }
}


module nut_holder(angle=0) {
    h = nut_rim[0] + nut_height;
    w = nut_width + 2 * nut_rim[1];
    t = max(shell_thickness, nut_rim[1]) + nut_width / 2;
    rotate(angle) translate([0, -t, 0]) difference() {
        union() {
            cylinder(h, d=w / cos(30), $fn=6);
            translate([-w / 2 / cos(30), 0, 0]) cube([w / cos(30), t, h]);
        }
        translate([0, 0, nut_rim[0]])
            cylinder(nut_height + e, d=nut_width / cos(30), $fn=6);
        translate([0, 0, -bottom_plate_thickness]) bolt_cutout();
    }
}


module nut_holders() {
    flip_x() for (v = nut_values) {
        pos = mount_points[v[0]] + [v[2], 0];
        a = v[1];
        translate(pos) nut_holder(a);
    }
    v1 = thumb_mount_points[0];
    v2 = thumb_mount_points[3];
    dv = (v2 - v1) / 2;
    a = atan2(-dv.x, dv.y);
    translate(v1 + dv) rotate(0) nut_holder(a + 90);
}


module i_pcb_holder() {
    l1 = i_pcb_holder_width;
    l2 = i_pcb_holder_thickness;
    t = i_pcb_holder_clearance;
    h1 = i_pcb_offset.z - t;
    h2 = h1 + i_pcb_size.z;
    pos = mount_points[i_pcb_mount_point_index];
    x1 = -pos.x + i_pcb_offset.x;
    x2 = -mount_points[0].x;
    y = pos.y + i_pcb_offset.y - i_pcb_size.y - shell_thickness - t;
    w1 = i_pcb_size.x;
    w2 = x2 - x1 + w1 / 2;
    d = i_pcb_mounting_hole_diameter - 2 * i_pcb_mounting_hole_clearance;
    o = i_pcb_mounting_hole_offset;
    ox1 = x2 - w2 / 2;
    ox2 = i_pcb_size.x / 2 - o;
    translate([ox1, y + l1 / 2, h1 / 2]) cube([w2, l1 + 2 * e, h1], center=true);
    translate([ox1, y - l2 / 2, h2 / 2]) cube([w2, l2, h2], center=true);
    translate([x1 + ox2, y + o + t, h1 - e]) cylinder(d=d, h=i_pcb_size.z);
    translate([x1 - ox2, y + o + t, h1 - e]) cylinder(d=d, h=i_pcb_size.z);
}


module mount(left=true) {
    translate([left ? -half_offset : half_offset, 0, 0]) flip_x(!left) {
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
        translate([0, 0, height_offset]) rotate (tilting_angle) {
            keys();
            thumb_connector_visualisation();
        }
        if (show_bottom_plate && $preview) {
            translate([0, 0, -bottom_plate_thickness]) bottom_plate();
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
    else if (render_preview) {
        render(10) children();
    }
    else {
        children();
    }
}


module keyboard() {
    // left half
    mount(left=true);
    // right half
    mount(left=false);
}


module m_pcb_pad_with_connector(conn_l, x1, x2, y, holes, hole_dir=1) {
    difference() {
        union() {
            w = m_pcb_straight_conn_width;
            square(m_pcb_pad_size, center=true);
            translate([x1, y]) square([w, conn_l]);
            translate([x2, y]) square([w, conn_l]);
        }
        if (holes) {
            circle(d=4);
            translate([3.81, 2.54] * hole_dir) circle(d=1.5);
            translate([2.54, 5.08] * hole_dir) circle(d=1.5);
            translate([-3.81, 2.54] * hole_dir) circle(d=1.5);
            translate([-2.54, 5.08] * hole_dir) circle(d=1.5);

        }
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
        rotate(-angle) translate([-r / 2 - w / 2 + e, e])
            square([r + w + 2 * e, 2 * r + w + 2 * e], center=true);
    }
}


module line(l, w) {
    translate([-w / 2, 0]) square([w, l]);
}


module col_connector(type, pos1, pos2) {
    w = m_pcb_col_connector_width;
    if (type == 2) {
        conn_l = pos1.x - pos2.x + 2 * e;
        translate(pos2 - [e, w / 2])
            square([conn_l, w]);
    }
    else {
        d = m_pcb_router_diameter / 2;
        r = abs(pos1.x - pos2.x) / 2 - d;
        l = abs(pos2.y - pos1.y) - 2 * r;
        translate(pos1) flip_x(type) {
            translate([-e, 0]) rotate(-90) line(d + 2 * e, w);
            translate([d, -r]) arc(r, w);
            translate([d + r, -r - l - e]) line(l + 2 * e, w);
            translate([2 * r + d, -r - l]) rotate(180) arc(r, w);
            translate([2 * r + d - e, -2 * r - l]) rotate(-90) line(d + 2 * e, w);
        }
    }
}


module thumb_connector_visualisation() {
    if (visualize_bending && $preview) {
        r = thumb_connector_vals[0];
        phi = thumb_connector_vals[1];
        bezier_points = thumb_connector_vals[2];
        f_pos = thumb_connector_vals[3];
        t_pos = thumb_connector_vals[4];
        f_val = thumb_connector_vals[5];
        t_val = thumb_connector_vals[6];
        alpha = f_val[3];
        beta = t_val[1];
        w = thumb_connector_width;

        color(matrix_pcb_color) {
            translate(f_pos) rotate([alpha, 0]) {
                // FPC connector pad
                translate([-fpc_pad_size.x / 2, 0, -m_pcb_thickness])
                    cube([fpc_pad_size.x, fpc_pad_size.y, m_pcb_thickness]);
                // arc near the finger cluster
                rotate(90) translate([0, -r, -m_pcb_thickness]) flip_x()
                    linear_extrude(m_pcb_thickness) arc(r, w, phi);
            }
            // arc near the thumb cluster
            translate(t_pos) rotate(thumb_rotation) rotate([beta, 0])
                rotate(-90) translate([-r, 0, -m_pcb_thickness])
                        linear_extrude(m_pcb_thickness) arc(r, w);
            // bending part of the connector approximated with a bezier curve
            polyhedron(bezier_visualisation_vertices,
                bezier_visualisation_faces, convexity=10);
        }

        translate(f_pos) rotate([alpha + 180, 0]) rotate(180)
            translate([0, 0, m_pcb_thickness]) fpc_connector();

        // keys
        flip_x() translate(f_val[0]) rotate([0, f_val[2]])
            translate(f_val[1]) rotate([alpha, 0]) key();
        translate(thumb_offset) rotate(thumb_rotation)
            translate(t_val[0]) rotate([beta, 0]) key(1.5);
    }
}


module matrix_pcb_outline(holes=false) {
    // finger cluster
    flip_x() for (i = iter(m_pcb_vals)) {
        ps = m_pcb_vals[i];
        s = home_row_index;
        if (i > 0) {
            cv = col_connector_vals[i - 1];
            col_connector(cv[0], cv[1], cv[2]);
        }
        for (j = iter(ps)) {
            m_pcb_pos = ps[j];
            m_pcb_ppos = ps[max(j - 1, 0)];
            w = m_pcb_straight_conn_width;
            conn_l = m_pcb_pos.y - m_pcb_ppos.y - m_pcb_pad_size.y + 2 * e;
            x1 = max(0, m_pcb_ppos.x - m_pcb_pos.x) - m_pcb_pad_size.x / 2;
            x2 = min(0, m_pcb_ppos.x - m_pcb_pos.x) + m_pcb_pad_size.x / 2 - w;
            y = -conn_l - m_pcb_pad_size.y / 2 + e;
            translate(m_pcb_pos) m_pcb_pad_with_connector(conn_l, x1, x2, y, holes);
        }
    }
    // thumb connector
    w = thumb_connector_width;
    r = thumb_connector_vals[0];
    phi = thumb_connector_vals[1];
    bezier_len = thumb_connector_vals[9];
    f_pos_2d = thumb_connector_vals[10];
    f_arc_2d = thumb_connector_vals[11];
    t_pos_2d = thumb_connector_vals[12];
    t_off_2d = thumb_connector_vals[13];
    translate(f_pos_2d) rotate(90) translate([0, -r]) flip_x() arc(r, w, phi);
    translate(f_arc_2d) rotate(phi + 180) line(bezier_len, w);
    translate(t_pos_2d) rotate(phi + 180) translate([0, -r]) flip_x() arc(r, w);
    // thumb cluster
    translate(t_off_2d) rotate(phi) for (i = iter(m_pcb_thumb_vals)) {
        pos = m_pcb_thumb_vals[i];
        ppos = m_pcb_thumb_vals[max(i - 1, 0)];
        conn_l = pos.y - ppos.y - m_pcb_pad_size.y + 2 * e;
        x1 = -m_pcb_pad_size.x / 2;
        x2 = m_pcb_pad_size.x / 2 - m_pcb_straight_conn_width;
        y = -conn_l - m_pcb_pad_size.y / 2 + e;
        translate(pos) m_pcb_pad_with_connector(conn_l, x1, x2, y, holes, -1);
    }
    // FPC connector pad
    fpc_val = m_pcb_vals[fpc_index][0];
    fpc_pos = fpc_val - fpc_offset;
    translate([-fpc_pos.x, fpc_pos.y]) square(fpc_pad_size, center=true);
}



// build bottom plate, either as 3D object or outline
if (build_bottom_plate) {
    bottom_plate();
}
else if (build_bottom_plate_outline) {
    projection(cut=true) translate([0, 0, -bottom_plate_thickness + e])
        bottom_plate();
}
// matrix PCB outline used for automatic PCB generation
else if (build_matrix_pcb_outline) {
    // keyboard parameters for automatic PCB generation
    echo(
        m_pcb_pad_size,
        home_row_index,
        -m_pcb_vals,
        m_pcb_thumb_vals,
        thumb_connector_vals,
        -col_connector_vals,
        m_pcb_col_connector_width,
        fpc_index,
        thumb_anchor_index,
        m_pcb_router_diameter,
        key_distance[0]
    );
    matrix_pcb_outline();
}
// build matrix PCB
else if (build_matrix_pcb) {
    color(matrix_pcb_color) linear_extrude(m_pcb_thickness)
    matrix_pcb_outline(holes=true);
    translate([0, 0, -thumb_connector_vals[4].z + switch_bottom_size.x / 2])
        thumb_connector_visualisation();
}
// build keyboard
else {
    keyboard();
}
