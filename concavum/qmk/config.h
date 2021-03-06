#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


// board specific settings
#if defined(__AVR_ATmega32U4__)
    // atmega32u4 specific settings
    // pin settings
    #define ALL_MATRIX_ROW_PINS F0, D7, F7, F6, F5, F4
    #define MATRIX_COL_PINS { D2, D3, D4, D5, D6, F1 }
    // i2c frequency
    #define F_SCL 800000UL
#elif defined(MCU_RP)
    // rp2040 specific settings
    // pin settings
    #define ALL_MATRIX_ROW_PINS GP9, GP10, GP19, GP20, GP18, GP26
    #define MATRIX_COL_PINS { GP8, GP7, GP6, GP5, GP4, GP27 }
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
