#include QMK_KEYBOARD_H
#include "mcp2301x.h"

#define SPLIT_MATRIX_COLS (MATRIX_COLS / 2)

typedef uint8_t mcp2301x_pin_t;

static const pin_t          row_pins[MATRIX_ROWS]           = MATRIX_ROW_PINS;
static const pin_t          col_pins[MAX_MATRIX_COLS / 2]   = MATRIX_COL_PINS;
static const mcp2301x_pin_t secondary_row_pins[MATRIX_ROWS] = SECONDARY_ROW_PINS;


static void select_row(uint8_t row) {
    // select primary row
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
    // select port expander row
    uint8_t port = ~secondary_row_pins[row];
    mcp2301x_write_port(port);
}


static void unselect_row(uint8_t row) {
    // only the primary row has to be unselected explicitly
    setPinInputHigh(row_pins[row]);
}


static matrix_row_t read_cols(void) {
    matrix_row_t state = 0;
    // read columns of the left side
    for (uint8_t col_index = 0; col_index < SPLIT_MATRIX_COLS; col_index++) {
        // select the column pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);
        // populate the matrix row with the state of the column pin
        state |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }
    // read columns of the right side
    matrix_row_t port = ~mcp2301x_read_port();
    state |= port << SPLIT_MATRIX_COLS;
    return state;
}


void matrix_init_custom(void) {
    // initialize rows (set pins as input and enable internal pullups)
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        setPinInputHigh(row_pins[i]);
    }
    // initialize columns (set pins as input and enable internal pullups)
    for (uint8_t i = 0; i < SPLIT_MATRIX_COLS; i++) {
        setPinInputHigh(col_pins[i]);
    }
    // initialize the port expander pins in a similar way
    mcp2301x_init();
}


bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;
    // check for changes in each row
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        matrix_row_t last_row_value = current_matrix[current_row];
        select_row(current_row);
        current_matrix[current_row] = read_cols();
        unselect_row(current_row);
        changed |= last_row_value != current_matrix[current_row];
    }
    return changed;
}
