#include QMK_KEYBOARD_H
#include "mcp23018.h"

#define MCP23018_ADDRESS 0b0100000

#define SECONDARY_ROW_PINS { (1<<7), (1<<4), (1<<3), (1<<2) }
#define F_SCL 800000UL

#define SPLIT_MATRIX_COLS (MATRIX_COLS / 2)

typedef uint8_t mcp23018_pin_t;

static const pin_t          row_pins[MATRIX_ROWS]           = MATRIX_ROW_PINS;
static const pin_t          col_pins[MATRIX_COLS]           = MATRIX_COL_PINS;
static const mcp23018_pin_t secondary_row_pins[MATRIX_ROWS] = SECONDARY_ROW_PINS;


static void select_row(uint8_t row) {
    // select primary row
    gpio_set_pin_output(row_pins[row]);
    gpio_write_pin_low(row_pins[row]);
    // select port expander row
    uint8_t port = ~secondary_row_pins[row];
    mcp23018_set_output(MCP23018_ADDRESS, mcp23018_PORTA, port);
}


static void unselect_row(uint8_t row) {
    // only the primary row has to be unselected explicitly
    gpio_set_pin_input_high(row_pins[row]);
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
    uint8_t port = 0xFF;
    mcp23018_read_pins(MCP23018_ADDRESS, mcp23018_PORTB, &port);
    state |= ~port << SPLIT_MATRIX_COLS;
    return state;
}


void matrix_init_custom(void) {
    // initialize rows (set pins as input and enable internal pullups)
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        gpio_set_pin_input_high(row_pins[i]);
    }
    // initialize columns (set pins as input and enable internal pullups)
    for (uint8_t i = 0; i < SPLIT_MATRIX_COLS; i++) {
        gpio_set_pin_input_high(col_pins[i]);
    }
    // initialize the port expander
    mcp23018_init(MCP23018_ADDRESS);
    mcp23018_set_config(MCP23018_ADDRESS, mcp23018_PORTA, ALL_OUTPUT);
    mcp23018_set_config(MCP23018_ADDRESS, mcp23018_PORTB, ALL_INPUT);
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
