DEBOUNCE_TYPE = sym_eager_pk

SRC += matrix.c \
	   mcp23017.c

QUANTUM_LIB_SRC += i2c_master.c
