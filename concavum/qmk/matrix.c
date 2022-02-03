#include QMK_KEYBOARD_H
#include "mcp23017.h"
#include "print.h"

typedef uint8_t mcp23017_pin_t;

static const pin_t          row_pins[MATRIX_ROWS]           = MATRIX_ROW_PINS;
static const mcp23017_pin_t secondary_row_pins[MATRIX_ROWS] = SECONDARY_ROW_PINS;


static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
    // select port expander row as well
    uint8_t port = ~secondary_row_pins[row];
    mcp23017_write_port(port);
}


static void unselect_row(uint8_t row) {
    // only the primary row has to be unselected explicitly
    setPinInputHigh(row_pins[row]); 
}


static matrix_row_t read_cols(void) {
    // read cols of the left side
    matrix_row_t state = ~PIND >> 2;
    // read cols of right side
    uint16_t port = mcp23017_read_port();
    state |= port << MATRIX_COLS;
    return state;
}


void matrix_init_custom(void) { 
    // initialize rows (set pins as input and enable internal pullups)
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
    // initialize columns (set pins as input and enable internal pullups)
    DDRD  &= 0b00000011;
    PORTD |= 0b11111100;
    // initialize the port expander pins in a similar way
    mcp23017_init();
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
