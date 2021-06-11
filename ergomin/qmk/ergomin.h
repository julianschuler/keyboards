#ifndef MANUFORM_H
#define MANUFORM_H

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05,                  k06, k07, k08, k09, k0A, k0B, \
    k0C, k0D, k0E, k0F, k10, k11,                  k12, k13, k14, k15, k16, k17, \
    k18, k19, k1A, k1B, k1C, k1D, k1E,        k1F, k20, k21, k22, k23, k24, k25, \
                    k26, k27, k28, k29,      k2A, k2B, k2C, k2D \
    ) { \
        { k00, k01, k02, k03, k04, k05,      k0B, k0A, k09, k08, k07, k06 }, \
        { k0C, k0D, k0E, k0F, k10, k11,      k17, k16, k15, k14, k13, k12 }, \
        { k18, k19, k1A, k1B, k1C, k1D,      k25, k24, k23, k22, k21, k20 }, \
        { XXX, k26, k27, k28, k29, k1E,      XXX, k2D, k2C, k2B, k2A, k1F }, \
    }



#endif
