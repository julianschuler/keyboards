# This file is a small interactive test to play around with bezier curves to
# approximate the bending of the thumb connector of the pcb.

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
from matplotlib.path import Path
from matplotlib import patches


def calc_bezier(a, k, n, x, y):
    p0 = (0, 0)
    p3 = (x, y)
    p1 = (k, 0)
    p2 = (x - n * np.cos(a), y - n * np.sin(a))
    return np.array([p0, p1, p2, p3])


def calc_curvature(t_list, vertices):
    res = []
    p0 = vertices[0]
    p1 = vertices[1]
    p2 = vertices[2]
    p3 = vertices[3]
    for t in t_list:
        v = (
            p0 * (-3 * t * t + 6 * t - 3)
            + p1 * (9 * t * t - 12 * t + 3)
            + p2 * (-9 * t * t + 6 * t)
            + p3 * 3 * t
        )
        a = p0 * (-6 * t + 6) + p1 * (18 * t - 12) + p2 * (-18 * t + 6) + p3 * 6 * t
        num = v[0] * a[1] - v[1] * a[0]
        denom = (v[0] * v[0] + v[1] * v[1]) ** (1.5)
        res.append(abs(num) / denom)
    return res


x_init = 40
y_init = 10
a_init = np.pi / 6
k_init = x_init / 2
n_init = x_init / 2

t = np.linspace(0, 1, 1000)
init_verts = calc_bezier(a_init, k_init, n_init, x_init, y_init)
init_curv = calc_curvature(t, init_verts)

codes = [
    Path.MOVETO,
    Path.CURVE4,
    Path.CURVE4,
    Path.CURVE4,
]

path = Path(init_verts, codes)

fig, ax = plt.subplots(1, 2)
ax[0].axis("equal")
ax[0].set_title("Bending Approximation")
ax[1].set_title("Curvature")
# ax[1].axis("equal")
patch = patches.PathPatch(path, facecolor="none", lw=2)
ax[0].add_patch(patch)

plt.subplots_adjust(bottom=0.35)


xs, ys = zip(*init_verts)
(line0,) = ax[0].plot(xs, ys, "x--", lw=2, color="black", ms=10)
(line1,) = ax[1].plot(t, init_curv)


def update(val):
    vertices = calc_bezier(alpha_slider.val, k_slider.val, n_slider.val, x_init, y_init)
    curvature = calc_curvature(t, vertices)
    path.vertices = vertices
    xs, ys = zip(*vertices)
    line0.set_xdata(xs)
    line0.set_ydata(ys)
    line1.set_ydata(curvature)
    fig.canvas.draw()


ax_alpha = plt.axes([0.15, 0.25, 0.65, 0.03])
alpha_slider = Slider(
    ax=ax_alpha, label="Angle", valmin=0, valmax=np.pi / 2, valinit=a_init
)

ax_k = plt.axes([0.15, 0.15, 0.65, 0.03])
k_slider = Slider(ax=ax_k, label="k", valmin=0.1, valmax=x_init, valinit=k_init)

ax_n = plt.axes([0.15, 0.05, 0.65, 0.03])
n_slider = Slider(ax=ax_n, label="n", valmin=0.1, valmax=x_init, valinit=n_init)

alpha_slider.on_changed(update)
k_slider.on_changed(update)
n_slider.on_changed(update)


plt.show()
