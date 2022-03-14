#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


// board specific settings
#if defined(__AVR_ATmega32U4__)
    // atmega32u4 specific settings
    // pin settings
    #define ALL_MATRIX_ROW_PINS F0, F7, F6, F5, F4, F1
    #define MATRIX_COL_PINS { D2, D3, D4, D5, D6, D7 }
    // i2c frequency
    #define F_SCL 800000UL
#elif defined(MCU_RP)
    // rp2040 specific settings
    // pin settings
    #define ALL_MATRIX_ROW_PINS GP9, GP19, GP20, GP18, GP26, GP27
    #define MATRIX_COL_PINS { GP8, GP7, GP6, GP5, GP4, GP10 }
    // i2c settings
    #define I2C_DRIVER I2CD2
    #define I2C1_SDA_PIN GP2
    #define I2C1_SCL_PIN GP3
    #define I2C1_CLOCK_SPEED 400000UL
#else
    #error MCU unsupported, supported MCUs: RP2040, atmega32u4.
#endif

// matrix settings, do not change
#define ALL_SECONDARY_ROW_PINS (1<<0), (1<<7), (1<<6), (1<<3), (1<<4), (1<<5)
#define MAX_MATRIX_COLS 12
#define DIODE_DIRECTION COL2ROW

// default matrix values to supress errors during first compilation
#define MATRIX_ROWS 6
#define MATRIX_COLS 12

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

// disable unused modules
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#endif
