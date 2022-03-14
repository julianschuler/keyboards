#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


// matrix settings
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D2, C6, C7, E2 }
#define MATRIX_COL_PINS { D3, D5, D4, D6, D7, B4 }
#define SECONDARY_ROW_PINS { (1<<7), (1<<4), (1<<3), (1<<2) }
#define DIODE_DIRECTION COL2ROW

// usb settings
#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0xC6AF
#define DEVICE_VER 0x0000
#define PRODUCT Ergomin
#define MANUFACTURER QMK

// timing settings
#define DEBOUNCE 15
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// disable unused modules
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// i2c frequency
#define F_SCL 800000UL

#endif
