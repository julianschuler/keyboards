#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


// matrix settings, only adjust MATRIX_ROWS, MATRIX_COLS and THUMB_KEYS
#define MATRIX_ROWS 4       // row count including the thumb row
#define MATRIX_COLS 12      // column count of both halves combined
#define THUMB_KEYS 6        // amount of thumb keys of both halves combined
#define HALF_MATRIX_COLS (MATRIX_COLS / 2)
#define ALL_MATRIX_ROW_PINS F0, F7, F6, F5, F4, F1
#define ALL_SECONDARY_ROW_PINS (1<<0), (1<<7), (1<<6), (1<<3), (1<<4), (1<<5)
#define DIODE_DIRECTION COL2ROW

// usb settings
#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0xC6AF
#define DEVICE_VER 0x0000
#define PRODUCT Concavum


// timing settings
#define DEBOUNCE 15
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// oneshot settings
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 200

// unicode input mode
#define UNICODE_SELECTED_MODES UC_LNX

// combo settings
#define COMBO_VARIABLE_LEN
#define COMBO_TERM 25

// disable unused modules
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif
