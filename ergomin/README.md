# Ergomin
## Overview
The Ergomin is the second keyboard I have built, following the Manuform. It is a 50% split keyboard inspired by the [ErgoDox](https://www.ergodox.io/) but with a focus on minimal finger movements and compact size.
Like its predecessor and the ErgoDox it features an ergonomic layout with ortholinear (non-staggered) columns. 

The Ergomin is mainly intended as a cheaper and easier to build version of the Manuform that still retains most of the benefits while adding a few of its own.

## Parts list
* 48 keyboard switches (Cherry MX, Gatheron, etc.)
* 42 keycaps 1U
* 6 keycaps 1.5U
* ~90g of PETG filament
* access to a 3D printer

## Building the firmware
The firmware is powered by QMK, [install QMK](https://docs.qmk.fm/#/newbs_getting_started) if not already done.
After the installation it is necassary to add a simlink to the qmk/ subfolder of this repository to the QMK keyboards/ directory, for linux e.g by
```
ln -s /path/to/ergomin/qmk /path/to/qmk/keyboards/ergomin
```

Now you should be able to compile the keyboard firmware by executing
```
qmk compile -kb ergomin -km default
```

Make sure to have a look at the excellent [QMK Documentation](https://docs.qmk.fm/#/newbs_building_firmware) on how to create and customize your own keymap.

## License
This project is licensed under the MIT license, see [`LICENSE.txt`](LICENSE.txt) for further information.

