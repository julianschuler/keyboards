MCU = RP2040
BOOTLOADER = rp2040

CUSTOM_MATRIX = lite

SRC += matrix.c \
	   mcp2301x.c

QUANTUM_LIB_SRC += i2c_master.c
