# board variant: kb2040 or atmega32u4
BOARD_VARIANT = kb2040

# debounce options
DEBOUNCE_TYPE = sym_eager_pk

# build options, chango to "no" to disable
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no         # Enable the encoder


# kb2040 specific settings
ifeq ($(BOARD_VARIANT), kb2040)
MCU = RP2040
BOOTLOADER = rp2040
endif

# atmega32u4 specific settings
ifeq ($(BOARD_VARIANT), atmega32u4)
MCU = atmega32u4
BOOTLOADER = atmel-dfu
F_CPU = 16000000
endif
