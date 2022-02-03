# board settings
MCU = atmega32u4
F_CPU = 16000000


CUSTOM_MATRIX = lite

SRC += matrix.c \
	   mcp23017.c

QUANTUM_LIB_SRC += i2c_master.c
