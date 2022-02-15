#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


// matrix settings, do not change
#define ALL_MATRIX_ROW_PINS F0, F7, F6, F5, F4, F1
#define ALL_SECONDARY_ROW_PINS (1<<0), (1<<7), (1<<6), (1<<3), (1<<4), (1<<5)
#define MAX_MATRIX_COLS 12
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

// disable unused modules
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif
