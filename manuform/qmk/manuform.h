#ifndef MANUFORM_H
#define MANUFORM_H

#include "quantum.h"


#define LAYOUT( \
    k00, k01, k02, k03, k04, k05,                  k06, k07, k08, k09, k0A, k0B, \
    k0C, k0D, k0E, k0F, k10, k11,  k12, k13, k14,  k15, k16, k17, k18, k19, k1A, \
    k1B, k1C, k1D, k1E, k1F, k20,  k21, k22, k23,  k24, k25, k26, k27, k28, k29, \
    \
                         k2A, k2B,                k2C, k2D, \
                           k2E, k2F,            k30, k31, \
                           k32, k33,            k34, k35 \
    ) { \
        { k00, k01, k02, k03, k04, k05 }, \
        { k0C, k0D, k0E, k0F, k10, k11 }, \
        { k1B, k1C, k1D, k1E, k1F, k20 }, \
        { k32, k33, k2E, k2F, k2A, k2B }, \
        \
        { k06, k07, k08, k09, k0A, k0B }, \
        { k15, k16, k17, k18, k19, k1A }, \
        { k24, k25, k26, k27, k28, k29 }, \
        { k2C, k2D, k30, k31, k34, k35 }, \
        \
        { k21, k22, k23, k12, k13, k14 } \
    }



#endif
