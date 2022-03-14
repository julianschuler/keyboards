#ifndef CONCAVUM_H
#define CONCAVUM_H

#include "quantum.h"


#define XXX KC_NO

// RESET keycode is not available for the rp2040 for now, replace with KC_NO
#if defined(MCU_RP)
    #define RESET KC_NO
#endif

// dummy layout to supress warnings
#define LAYOUT(...) {__VA_ARGS__}

// get the first elements from the parameters
#define _GET_ELEMS_1(a, b, c, d, e, f) a
#define _GET_ELEMS_2(a, b, c, d, e, f) a, b
#define _GET_ELEMS_3(a, b, c, d, e, f) a, b, c
#define _GET_ELEMS_4(a, b, c, d, e, f) a, b, c, d
#define _GET_ELEMS_5(a, b, c, d, e, f) a, b, c, d, e
#define _GET_ELEMS_6(a, b, c, d, e, f) a, b, c, d, e, f
#define GET_ELEMS_1(...) _GET_ELEMS_1(__VA_ARGS__)
#define GET_ELEMS_2(...) _GET_ELEMS_2(__VA_ARGS__)
#define GET_ELEMS_3(...) _GET_ELEMS_3(__VA_ARGS__)
#define GET_ELEMS_4(...) _GET_ELEMS_4(__VA_ARGS__)
#define GET_ELEMS_5(...) _GET_ELEMS_5(__VA_ARGS__)
#define GET_ELEMS_6(...) _GET_ELEMS_6(__VA_ARGS__)
#define GET_ELEMS(N) CONCAT(GET_ELEMS_, N)

// select only the row pins actually used
#define MATRIX_ROW_PINS { GET_ELEMS(MATRIX_ROWS)(ALL_MATRIX_ROW_PINS) }
#define SECONDARY_ROW_PINS { GET_ELEMS(MATRIX_ROWS)(ALL_SECONDARY_ROW_PINS) }


// define ROW according to the amount of columns
#if MATRIX_COLS == 4
    #define ROW(a, b, c, d) \
               {XXX, XXX, XXX, XXX, a, b, c, d, XXX, XXX, XXX, XXX}
#elif MATRIX_COLS == 6
    #define ROW(a, b, c, d, e, f) \
               {XXX, XXX, XXX, a, b, c, d, e, f, XXX, XXX, XXX}
#elif MATRIX_COLS == 8
    #define ROW(a, b, c, d, e, f, g, h) \
               {XXX, XXX, a, b, c, d, f, g, h, i, XXX, XXX}
#elif MATRIX_COLS == 10
    #define ROW(a, b, c, d, e, f, g, h, i, j) \
               {XXX, a, b, c, d, e, f, g, h, i, j, XXX}
#elif MATRIX_COLS == 12
    #define ROW(a, b, c, d, e, f, g, h, i, j, k, l) \
               {a, b, c, d, e, f, g, h, i, j, k, l}
#else
    // column count is out of range, report error
    #error MATRIX_COLS is not within 4 to 12.
#endif


// define T_ROW according to the amount of thumb keys
#if THUMB_KEYS == 2
    #define T_ROW(a, b) \
                 {XXX, XXX, XXX, XXX, XXX, a, b, XXX, XXX, XXX, XXX, XXX}
#elif THUMB_KEYS == 4
    #define T_ROW(a, b, c, d) \
                 {XXX, XXX, XXX, XXX, a, b, c, d, XXX, XXX, XXX, XXX}
#elif THUMB_KEYS == 6
    #define T_ROW(a, b, c, d, e, f) \
                 {XXX, XXX, XXX, a, b, c, d, e, f, XXX, XXX, XXX}
#elif THUMB_KEYS == 8
    #define T_ROW(a, b, c, d, e, f, g, h) \
                 {XXX, XXX, a, b, c, d, e, f, g, h, XXX, XXX}
#elif THUMB_KEYS == 10
    #define T_ROW(a, b, c, d, e, f, g, h, i, j) \
                 {XXX, a, b, c, d, e, f, g, h, i, j, XXX}
#elif THUMB_KEYS == 12
    #define T_ROW(a, b, c, d, e, f, g, h, i, j, k, l) \
                 {a, b, c, d, e, f, g, h, i, j, k, l}
#else
    // thumb key count is out of range, report error
    #error THUMB_KEYS is not within 2 to 12.
#endif


// define LAYER according to the amount of rows
#if MATRIX_ROWS == 2
    #define LAYER(row1, thumb_row) \
                  {thumb_row, row1}
#elif MATRIX_ROWS == 3
    #define LAYER(row2, row1, thumb_row) \
                  {thumb_row, row1, row2}
#elif MATRIX_ROWS == 4
    #define LAYER(row3, row2, row1, thumb_row) \
                  {thumb_row, row1, row2, row3}
#elif MATRIX_ROWS == 5
    #define LAYER(row4, row3, row2, row1, thumb_row) \
                  {thumb_row, row1, row2, row3, row4}
#elif MATRIX_ROWS == 6
    #define LAYER(row5, row4, row3, row2, row1, thumb_row) \
                  {thumb_row, row1, row2, row3, row4, row5}
#else
    // row count is out of range, report error
    #error MATRIX_ROWS is not within 2 to 6.
#endif


#endif
