#ifndef CONCAVUM_H
#define CONCAVUM_H

/* This file was automatically generated. For modifications, use
 * the provided python script 'generate-concavum-h.py' instead.
 */

#include "quantum.h"

#define XXX KC_NO

// define LAYOUT and _GET_ROW_PINS depending on ROWS, COLS and THUMB_KEYS
#if ROWS == 1
  #define _GET_ROW_PINS(p0, p1, p2, p3, p4, p5) { p0 }
  #if COLS == 2
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                     k00,     k01 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                k00, k01,     k02, k03 \
      ) { \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                           k00, k01, k02,     k03, k04, k05 \
      ) { \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                      k00, k01, k02, k03,     k04, k05, k06, k07 \
      ) { \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                 k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09 \
      ) { \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
            k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B \
      ) { \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 4
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                     k00,     k01 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                k00, k01,     k02, k03 \
      ) { \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                           k00, k01, k02,     k03, k04, k05 \
      ) { \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                      k00, k01, k02, k03,     k04, k05, k06, k07 \
      ) { \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                 k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09 \
      ) { \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
            k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B \
      ) { \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 6
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                     k00,     k01 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                k00, k01,     k02, k03 \
      ) { \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                           k00, k01, k02,     k03, k04, k05 \
      ) { \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                      k00, k01, k02, k03,     k04, k05, k06, k07 \
      ) { \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                 k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09 \
      ) { \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
            k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B \
      ) { \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 8
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                     k00,     k01 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                k00, k01,     k02, k03 \
      ) { \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                           k00, k01, k02,     k03, k04, k05 \
      ) { \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                      k00, k01, k02, k03,     k04, k05, k06, k07 \
      ) { \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                 k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09 \
      ) { \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
            k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B \
      ) { \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 10
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                     k00,     k01 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                k00, k01,     k02, k03 \
      ) { \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                           k00, k01, k02,     k03, k04, k05 \
      ) { \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                      k00, k01, k02, k03,     k04, k05, k06, k07 \
      ) { \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                 k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09 \
      ) { \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
            k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B \
      ) { \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 12
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                     k00,     k01 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                k00, k01,     k02, k03 \
      ) { \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                           k00, k01, k02,     k03, k04, k05 \
      ) { \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                      k00, k01, k02, k03,     k04, k05, k06, k07 \
      ) { \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                 k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09 \
      ) { \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
            k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B \
      ) { \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #else
    #error COLS is not in [2, 4, 6, 8, 10, 12].
  #endif
#elif ROWS == 2
  #define _GET_ROW_PINS(p0, p1, p2, p3, p4, p5) { p0, p1 }
  #if COLS == 2
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                   k00,         k01, \
                                     k10,     k11 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                   k00,         k01, \
                                k10, k11,     k12, k13 \
      ) { \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                                   k00,         k01, \
                           k10, k11, k12,     k13, k14, k15 \
      ) { \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                                   k00,         k01, \
                      k10, k11, k12, k13,     k14, k15, k16, k17 \
      ) { \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                                   k00,         k01, \
                 k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19 \
      ) { \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                                   k00,         k01, \
            k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B \
      ) { \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 4
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                                     k10,     k11 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                                k10, k11,     k12, k13 \
      ) { \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                           k10, k11, k12,     k13, k14, k15 \
      ) { \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                      k10, k11, k12, k13,     k14, k15, k16, k17 \
      ) { \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                 k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19 \
      ) { \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
            k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B \
      ) { \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 6
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                                     k10,     k11 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                                k10, k11,     k12, k13 \
      ) { \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                           k10, k11, k12,     k13, k14, k15 \
      ) { \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                      k10, k11, k12, k13,     k14, k15, k16, k17 \
      ) { \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                 k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19 \
      ) { \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
            k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B \
      ) { \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 8
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                                     k10,     k11 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                                k10, k11,     k12, k13 \
      ) { \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                           k10, k11, k12,     k13, k14, k15 \
      ) { \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                      k10, k11, k12, k13,     k14, k15, k16, k17 \
      ) { \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                 k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19 \
      ) { \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
            k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B \
      ) { \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 10
    #if THUMB_KEYS == 2
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
                                     k10,     k11 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
                                k10, k11,     k12, k13 \
      ) { \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
                           k10, k11, k12,     k13, k14, k15 \
      ) { \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
                      k10, k11, k12, k13,     k14, k15, k16, k17 \
      ) { \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
                 k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19 \
      ) { \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
            k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B \
      ) { \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 12
    #if THUMB_KEYS == 2
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
                                     k10,     k11 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
                                k10, k11,     k12, k13 \
      ) { \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
                           k10, k11, k12,     k13, k14, k15 \
      ) { \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
                      k10, k11, k12, k13,     k14, k15, k16, k17 \
      ) { \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
                 k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19 \
      ) { \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
            k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B \
      ) { \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #else
    #error COLS is not in [2, 4, 6, 8, 10, 12].
  #endif
#elif ROWS == 3
  #define _GET_ROW_PINS(p0, p1, p2, p3, p4, p5) { p0, p1, p2 }
  #if COLS == 2
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                     k20,     k21 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                k20, k21,     k22, k23 \
      ) { \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                           k20, k21, k22,     k23, k24, k25 \
      ) { \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                      k20, k21, k22, k23,     k24, k25, k26, k27 \
      ) { \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                 k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29 \
      ) { \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
            k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B \
      ) { \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 4
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                                     k20,     k21 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                                k20, k21,     k22, k23 \
      ) { \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                           k20, k21, k22,     k23, k24, k25 \
      ) { \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                      k20, k21, k22, k23,     k24, k25, k26, k27 \
      ) { \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                 k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29 \
      ) { \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
            k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B \
      ) { \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 6
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                                     k20,     k21 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                                k20, k21,     k22, k23 \
      ) { \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                           k20, k21, k22,     k23, k24, k25 \
      ) { \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                      k20, k21, k22, k23,     k24, k25, k26, k27 \
      ) { \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                 k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29 \
      ) { \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
            k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B \
      ) { \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 8
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                                     k20,     k21 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                                k20, k21,     k22, k23 \
      ) { \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                           k20, k21, k22,     k23, k24, k25 \
      ) { \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                      k20, k21, k22, k23,     k24, k25, k26, k27 \
      ) { \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                 k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29 \
      ) { \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
            k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B \
      ) { \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 10
    #if THUMB_KEYS == 2
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
                                     k20,     k21 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
                                k20, k21,     k22, k23 \
      ) { \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
                           k20, k21, k22,     k23, k24, k25 \
      ) { \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
                      k20, k21, k22, k23,     k24, k25, k26, k27 \
      ) { \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
                 k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29 \
      ) { \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
            k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B \
      ) { \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 12
    #if THUMB_KEYS == 2
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
                                     k20,     k21 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
                                k20, k21,     k22, k23 \
      ) { \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
                           k20, k21, k22,     k23, k24, k25 \
      ) { \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
                      k20, k21, k22, k23,     k24, k25, k26, k27 \
      ) { \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
                 k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29 \
      ) { \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
            k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B \
      ) { \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #else
    #error COLS is not in [2, 4, 6, 8, 10, 12].
  #endif
#elif ROWS == 4
  #define _GET_ROW_PINS(p0, p1, p2, p3, p4, p5) { p0, p1, p2, p3 }
  #if COLS == 2
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                     k30,     k31 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                k30, k31,     k32, k33 \
      ) { \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                           k30, k31, k32,     k33, k34, k35 \
      ) { \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                      k30, k31, k32, k33,     k34, k35, k36, k37 \
      ) { \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                 k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39 \
      ) { \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
            k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B \
      ) { \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 4
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                                     k30,     k31 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                                k30, k31,     k32, k33 \
      ) { \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                           k30, k31, k32,     k33, k34, k35 \
      ) { \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                      k30, k31, k32, k33,     k34, k35, k36, k37 \
      ) { \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                 k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39 \
      ) { \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
            k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B \
      ) { \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 6
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                                     k30,     k31 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                                k30, k31,     k32, k33 \
      ) { \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                           k30, k31, k32,     k33, k34, k35 \
      ) { \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                      k30, k31, k32, k33,     k34, k35, k36, k37 \
      ) { \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                 k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39 \
      ) { \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
            k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B \
      ) { \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 8
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                                     k30,     k31 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                                k30, k31,     k32, k33 \
      ) { \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                           k30, k31, k32,     k33, k34, k35 \
      ) { \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                      k30, k31, k32, k33,     k34, k35, k36, k37 \
      ) { \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                 k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39 \
      ) { \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
            k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B \
      ) { \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 10
    #if THUMB_KEYS == 2
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
                                     k30,     k31 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
                                k30, k31,     k32, k33 \
      ) { \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
                           k30, k31, k32,     k33, k34, k35 \
      ) { \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
                      k30, k31, k32, k33,     k34, k35, k36, k37 \
      ) { \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
                 k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39 \
      ) { \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
            k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B \
      ) { \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 12
    #if THUMB_KEYS == 2
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
                                     k30,     k31 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
                                k30, k31,     k32, k33 \
      ) { \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
                           k30, k31, k32,     k33, k34, k35 \
      ) { \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
                      k30, k31, k32, k33,     k34, k35, k36, k37 \
      ) { \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
                 k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39 \
      ) { \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
            k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B \
      ) { \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #else
    #error COLS is not in [2, 4, 6, 8, 10, 12].
  #endif
#elif ROWS == 5
  #define _GET_ROW_PINS(p0, p1, p2, p3, p4, p5) { p0, p1, p2, p3, p4 }
  #if COLS == 2
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                     k40,     k41 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                k40, k41,     k42, k43 \
      ) { \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                           k40, k41, k42,     k43, k44, k45 \
      ) { \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                      k40, k41, k42, k43,     k44, k45, k46, k47 \
      ) { \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                 k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49 \
      ) { \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
            k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B \
      ) { \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 4
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                                     k40,     k41 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                                k40, k41,     k42, k43 \
      ) { \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                           k40, k41, k42,     k43, k44, k45 \
      ) { \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                      k40, k41, k42, k43,     k44, k45, k46, k47 \
      ) { \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                 k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49 \
      ) { \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
            k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B \
      ) { \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 6
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                                     k40,     k41 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                                k40, k41,     k42, k43 \
      ) { \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                           k40, k41, k42,     k43, k44, k45 \
      ) { \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                      k40, k41, k42, k43,     k44, k45, k46, k47 \
      ) { \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                 k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49 \
      ) { \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
            k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B \
      ) { \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 8
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                                     k40,     k41 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                                k40, k41,     k42, k43 \
      ) { \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                           k40, k41, k42,     k43, k44, k45 \
      ) { \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                      k40, k41, k42, k43,     k44, k45, k46, k47 \
      ) { \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                 k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49 \
      ) { \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
            k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B \
      ) { \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 10
    #if THUMB_KEYS == 2
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
                                     k40,     k41 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
                                k40, k41,     k42, k43 \
      ) { \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
                           k40, k41, k42,     k43, k44, k45 \
      ) { \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
                      k40, k41, k42, k43,     k44, k45, k46, k47 \
      ) { \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
                 k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49 \
      ) { \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
            k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B \
      ) { \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 12
    #if THUMB_KEYS == 2
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
                                     k40,     k41 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
                                k40, k41,     k42, k43 \
      ) { \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
                           k40, k41, k42,     k43, k44, k45 \
      ) { \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
                      k40, k41, k42, k43,     k44, k45, k46, k47 \
      ) { \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
                 k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49 \
      ) { \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
            k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B \
      ) { \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #else
    #error COLS is not in [2, 4, 6, 8, 10, 12].
  #endif
#elif ROWS == 6
  #define _GET_ROW_PINS(p0, p1, p2, p3, p4, p5) { p0, p1, p2, p3, p4, p5 }
  #if COLS == 2
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                   k40,         k41, \
                                     k50,     k51 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k50,     k51, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                   k40,         k41, \
                                k50, k51,     k52, k53 \
      ) { \
          { XXX, XXX, XXX, XXX, k50, k51,     k52, k53, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                   k40,         k41, \
                           k50, k51, k52,     k53, k54, k55 \
      ) { \
          { XXX, XXX, XXX, k50, k51, k52,     k53, k54, k55, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                   k40,         k41, \
                      k50, k51, k52, k53,     k54, k55, k56, k57 \
      ) { \
          { XXX, XXX, k50, k51, k52, k53,     k54, k55, k56, k57, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                   k40,         k41, \
                 k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59 \
      ) { \
          { XXX, k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                                   k00,         k01, \
                                   k10,         k11, \
                                   k20,         k21, \
                                   k30,         k31, \
                                   k40,         k41, \
            k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B \
      ) { \
          { k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B }, \
          { XXX, XXX, XXX, XXX, XXX, k40,     k41, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k30,     k31, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k20,     k21, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k10,     k11, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, XXX, k00,     k01, XXX, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 4
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                              k40, k41,         k42, k43, \
                                     k50,     k51 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k50,     k51, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                              k40, k41,         k42, k43, \
                                k50, k51,     k52, k53 \
      ) { \
          { XXX, XXX, XXX, XXX, k50, k51,     k52, k53, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                              k40, k41,         k42, k43, \
                           k50, k51, k52,     k53, k54, k55 \
      ) { \
          { XXX, XXX, XXX, k50, k51, k52,     k53, k54, k55, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                              k40, k41,         k42, k43, \
                      k50, k51, k52, k53,     k54, k55, k56, k57 \
      ) { \
          { XXX, XXX, k50, k51, k52, k53,     k54, k55, k56, k57, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                              k40, k41,         k42, k43, \
                 k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59 \
      ) { \
          { XXX, k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59, XXX }, \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                              k00, k01,         k02, k03, \
                              k10, k11,         k12, k13, \
                              k20, k21,         k22, k23, \
                              k30, k31,         k32, k33, \
                              k40, k41,         k42, k43, \
            k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B \
      ) { \
          { k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B }, \
          { XXX, XXX, XXX, XXX, k40, k41,     k42, k43, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k30, k31,     k32, k33, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k20, k21,     k22, k23, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k10, k11,     k12, k13, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, XXX, k00, k01,     k02, k03, XXX, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 6
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                         k40, k41, k42,         k43, k44, k45, \
                                     k50,     k51 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k50,     k51, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                         k40, k41, k42,         k43, k44, k45, \
                                k50, k51,     k52, k53 \
      ) { \
          { XXX, XXX, XXX, XXX, k50, k51,     k52, k53, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                         k40, k41, k42,         k43, k44, k45, \
                           k50, k51, k52,     k53, k54, k55 \
      ) { \
          { XXX, XXX, XXX, k50, k51, k52,     k53, k54, k55, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                         k40, k41, k42,         k43, k44, k45, \
                      k50, k51, k52, k53,     k54, k55, k56, k57 \
      ) { \
          { XXX, XXX, k50, k51, k52, k53,     k54, k55, k56, k57, XXX, XXX }, \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                         k40, k41, k42,         k43, k44, k45, \
                 k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59 \
      ) { \
          { XXX, k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59, XXX }, \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                         k00, k01, k02,         k03, k04, k05, \
                         k10, k11, k12,         k13, k14, k15, \
                         k20, k21, k22,         k23, k24, k25, \
                         k30, k31, k32,         k33, k34, k35, \
                         k40, k41, k42,         k43, k44, k45, \
            k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B \
      ) { \
          { k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B }, \
          { XXX, XXX, XXX, k40, k41, k42,     k43, k44, k45, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k30, k31, k32,     k33, k34, k35, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k20, k21, k22,     k23, k24, k25, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k10, k11, k12,     k13, k14, k15, XXX, XXX, XXX }, \
          { XXX, XXX, XXX, k00, k01, k02,     k03, k04, k05, XXX, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 8
    #if THUMB_KEYS == 2
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                    k40, k41, k42, k43,         k44, k45, k46, k47, \
                                     k50,     k51 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k50,     k51, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                    k40, k41, k42, k43,         k44, k45, k46, k47, \
                                k50, k51,     k52, k53 \
      ) { \
          { XXX, XXX, XXX, XXX, k50, k51,     k52, k53, XXX, XXX, XXX, XXX }, \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                    k40, k41, k42, k43,         k44, k45, k46, k47, \
                           k50, k51, k52,     k53, k54, k55 \
      ) { \
          { XXX, XXX, XXX, k50, k51, k52,     k53, k54, k55, XXX, XXX, XXX }, \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                    k40, k41, k42, k43,         k44, k45, k46, k47, \
                      k50, k51, k52, k53,     k54, k55, k56, k57 \
      ) { \
          { XXX, XXX, k50, k51, k52, k53,     k54, k55, k56, k57, XXX, XXX }, \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                    k40, k41, k42, k43,         k44, k45, k46, k47, \
                 k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59 \
      ) { \
          { XXX, k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59, XXX }, \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
                    k00, k01, k02, k03,         k04, k05, k06, k07, \
                    k10, k11, k12, k13,         k14, k15, k16, k17, \
                    k20, k21, k22, k23,         k24, k25, k26, k27, \
                    k30, k31, k32, k33,         k34, k35, k36, k37, \
                    k40, k41, k42, k43,         k44, k45, k46, k47, \
            k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B \
      ) { \
          { k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B }, \
          { XXX, XXX, k40, k41, k42, k43,     k44, k45, k46, k47, XXX, XXX }, \
          { XXX, XXX, k30, k31, k32, k33,     k34, k35, k36, k37, XXX, XXX }, \
          { XXX, XXX, k20, k21, k22, k23,     k24, k25, k26, k27, XXX, XXX }, \
          { XXX, XXX, k10, k11, k12, k13,     k14, k15, k16, k17, XXX, XXX }, \
          { XXX, XXX, k00, k01, k02, k03,     k04, k05, k06, k07, XXX, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 10
    #if THUMB_KEYS == 2
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
               k40, k41, k42, k43, k44,         k45, k46, k47, k48, k49, \
                                     k50,     k51 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k50,     k51, XXX, XXX, XXX, XXX, XXX }, \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
               k40, k41, k42, k43, k44,         k45, k46, k47, k48, k49, \
                                k50, k51,     k52, k53 \
      ) { \
          { XXX, XXX, XXX, XXX, k50, k51,     k52, k53, XXX, XXX, XXX, XXX }, \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
               k40, k41, k42, k43, k44,         k45, k46, k47, k48, k49, \
                           k50, k51, k52,     k53, k54, k55 \
      ) { \
          { XXX, XXX, XXX, k50, k51, k52,     k53, k54, k55, XXX, XXX, XXX }, \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
               k40, k41, k42, k43, k44,         k45, k46, k47, k48, k49, \
                      k50, k51, k52, k53,     k54, k55, k56, k57 \
      ) { \
          { XXX, XXX, k50, k51, k52, k53,     k54, k55, k56, k57, XXX, XXX }, \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
               k40, k41, k42, k43, k44,         k45, k46, k47, k48, k49, \
                 k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59 \
      ) { \
          { XXX, k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59, XXX }, \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
               k00, k01, k02, k03, k04,         k05, k06, k07, k08, k09, \
               k10, k11, k12, k13, k14,         k15, k16, k17, k18, k19, \
               k20, k21, k22, k23, k24,         k25, k26, k27, k28, k29, \
               k30, k31, k32, k33, k34,         k35, k36, k37, k38, k39, \
               k40, k41, k42, k43, k44,         k45, k46, k47, k48, k49, \
            k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B \
      ) { \
          { k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B }, \
          { XXX, k40, k41, k42, k43, k44,     k45, k46, k47, k48, k49, XXX }, \
          { XXX, k30, k31, k32, k33, k34,     k35, k36, k37, k38, k39, XXX }, \
          { XXX, k20, k21, k22, k23, k24,     k25, k26, k27, k28, k29, XXX }, \
          { XXX, k10, k11, k12, k13, k14,     k15, k16, k17, k18, k19, XXX }, \
          { XXX, k00, k01, k02, k03, k04,     k05, k06, k07, k08, k09, XXX }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #elif COLS == 12
    #if THUMB_KEYS == 2
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
          k40, k41, k42, k43, k44, k45,         k46, k47, k48, k49, k4A, k4B, \
                                     k50,     k51 \
      ) { \
          { XXX, XXX, XXX, XXX, XXX, k50,     k51, XXX, XXX, XXX, XXX, XXX }, \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 4
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
          k40, k41, k42, k43, k44, k45,         k46, k47, k48, k49, k4A, k4B, \
                                k50, k51,     k52, k53 \
      ) { \
          { XXX, XXX, XXX, XXX, k50, k51,     k52, k53, XXX, XXX, XXX, XXX }, \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 6
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
          k40, k41, k42, k43, k44, k45,         k46, k47, k48, k49, k4A, k4B, \
                           k50, k51, k52,     k53, k54, k55 \
      ) { \
          { XXX, XXX, XXX, k50, k51, k52,     k53, k54, k55, XXX, XXX, XXX }, \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 8
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
          k40, k41, k42, k43, k44, k45,         k46, k47, k48, k49, k4A, k4B, \
                      k50, k51, k52, k53,     k54, k55, k56, k57 \
      ) { \
          { XXX, XXX, k50, k51, k52, k53,     k54, k55, k56, k57, XXX, XXX }, \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 10
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
          k40, k41, k42, k43, k44, k45,         k46, k47, k48, k49, k4A, k4B, \
                 k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59 \
      ) { \
          { XXX, k50, k51, k52, k53, k54,     k55, k56, k57, k58, k59, XXX }, \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #elif THUMB_KEYS == 12
      #define LAYOUT( \
          k00, k01, k02, k03, k04, k05,         k06, k07, k08, k09, k0A, k0B, \
          k10, k11, k12, k13, k14, k15,         k16, k17, k18, k19, k1A, k1B, \
          k20, k21, k22, k23, k24, k25,         k26, k27, k28, k29, k2A, k2B, \
          k30, k31, k32, k33, k34, k35,         k36, k37, k38, k39, k3A, k3B, \
          k40, k41, k42, k43, k44, k45,         k46, k47, k48, k49, k4A, k4B, \
            k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B \
      ) { \
          { k50, k51, k52, k53, k54, k55,     k56, k57, k58, k59, k5A, k5B }, \
          { k40, k41, k42, k43, k44, k45,     k46, k47, k48, k49, k4A, k4B }, \
          { k30, k31, k32, k33, k34, k35,     k36, k37, k38, k39, k3A, k3B }, \
          { k20, k21, k22, k23, k24, k25,     k26, k27, k28, k29, k2A, k2B }, \
          { k10, k11, k12, k13, k14, k15,     k16, k17, k18, k19, k1A, k1B }, \
          { k00, k01, k02, k03, k04, k05,     k06, k07, k08, k09, k0A, k0B }, \
      }
    #else
      #error THUMB_KEYS is not in [2, 4, 6, 8, 10, 12].
    #endif
  #else
    #error COLS is not in [2, 4, 6, 8, 10, 12].
  #endif
#else
  #error ROWS is not in [1, 2, 3, 4, 5, 6].
#endif

// double define allows macros to work within GET_ROW_PINS
#define GET_ROW_PINS(...) _GET_ROW_PINS(__VA_ARGS__)

// select actually used row pins with previously defined macro
#define SECONDARY_ROW_PINS  GET_ROW_PINS(ALL_SECONDARY_ROW_PINS)

#endif
