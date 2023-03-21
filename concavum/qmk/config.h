#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


// pin settings
#define ALL_MATRIX_ROW_PINS GP9, GP10, GP19, GP20, GP18, GP26
#define MATRIX_COL_PINS { GP8, GP7, GP6, GP5, GP4, GP27 }
// i2c settings
#define I2C_DRIVER I2CD2
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
#define I2C1_CLOCK_SPEED 400000UL

// matrix settings, do not change
#define ALL_SECONDARY_ROW_PINS (1<<0), (1<<7), (1<<6), (1<<3), (1<<4), (1<<5)
#define MAX_MATRIX_COLS 12
#define DIODE_DIRECTION COL2ROW

// default matrix values to supress errors during first compilation
#define MATRIX_ROWS 6
#define MATRIX_COLS 12

// activate entering the boot loader by double tapping the reset button
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// usb settings
#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0xD6AF
#define DEVICE_VER 0x0000
#define PRODUCT Concavum
#define MANUFACTURER QMK

// timing settings
#define DEBOUNCE 15
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#endif
