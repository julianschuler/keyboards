# rp2040 settings
ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no # unsupported by ChibiOs for now

# atmega32u4 settings
F_CPU = 16000000


CUSTOM_MATRIX = lite

SRC += matrix.c \
	   mcp23017.c

QUANTUM_LIB_SRC += i2c_master.c
