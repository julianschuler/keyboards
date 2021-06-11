#include QMK_KEYBOARD_H
#include "mcp23017.h"
#include "print.h"

#define SPLIT_MATRIX_COLS (MATRIX_COLS / 2)

typedef uint8_t mcp23017_pin_t;

static const pin_t          row_pins[MATRIX_ROWS]                 = MATRIX_ROW_PINS;
static const pin_t          col_pins[SPLIT_MATRIX_COLS]           = MATRIX_COL_PINS;
static const mcp23017_pin_t secondary_row_pins[MATRIX_ROWS]       = SECONDARY_ROW_PINS_ARRAY;


static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
     
    uint8_t port = 0xFF & ~secondary_row_pins[row];
    mcp23017_write_port(port);
    /* uprintf("%d, %d\n", ret, gpioa); */
}


static void unselect_row(uint8_t row) {
    setPinInputHigh(row_pins[row]); 
}


static matrix_row_t read_cols(void) {
    matrix_row_t state = 0;
    for (uint8_t col_index = 0; col_index < SPLIT_MATRIX_COLS; col_index++) {
        // Select the col pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);
        // Populate the matrix row with the state of the col pin
        state |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }
    /* state = (~PIND >> 3) | ((~PINB & (1 << 4)) << 1); */
    // read cols of right side
    uint16_t port = mcp23017_read_port();
    state |= port << SPLIT_MATRIX_COLS;
    /* uprintf("%d\n", port); */
    return state;
}


void matrix_init_custom(void) { 
    // init rows
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
    // init cols
    for (uint8_t x = 0; x < SPLIT_MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
    mcp23017_init();
}


bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        matrix_row_t last_row_value = current_matrix[current_row];
        select_row(current_row);
        current_matrix[current_row] = read_cols();
        unselect_row(current_row);
        changed |= last_row_value != current_matrix[current_row];
    }

    return changed;
}
