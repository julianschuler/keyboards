#ifndef CONFIG_H
#define CONFIG_H

// activate entering the boot loader by double tapping the reset button
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// split keyboard settings
#define USB_VBUS_PIN GP28
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP2
#define SERIAL_USART_RX_PIN GP3
#define SERIAL_USART_PIN_SWAP

#endif
