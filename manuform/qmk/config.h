#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


// matrix settings
#define MATRIX_ROWS 9
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { D7, C6, D4, D0, F7, F6, F5, F4, F1 }
#define MATRIX_COL_PINS { D6, B7, B6, B5, B4, E6 }
#define DIODE_DIRECTION COL2ROW

// encoder settings
#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }
#define ENCODER_RESOLUTION 4

// usb settings
#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0xB6AF
#define DEVICE_VER 0x0000
#define PRODUCT Manuform

// timing settings
#define DEBOUNCE 15
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// disable unused modules
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif
