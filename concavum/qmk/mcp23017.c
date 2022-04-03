#include QMK_KEYBOARD_H
#include "i2c_master.h"
#include "mcp23017.h"


#if defined(__AVR__)
    #define SLEEP_MS(t) _delay_ms(t)
#elif defined(__CHIBIOS__)
    #define SLEEP_MS(t) chThdSleepMilliseconds(t)
#endif


static i2c_status_t mcp23017_status = I2C_STATUS_ERROR;


void mcp23017_init(void) {
    mcp23017_status = I2C_STATUS_SUCCESS;

    SLEEP_MS(MCP23017_STARTUP_DELAY);
    i2c_init();

    // set pin direction
    const uint8_t pin_dir[] = { IODIRA, 0b00000000, 0b11111111 };
    mcp23017_status = i2c_transmit(MCP23017_ADDR, pin_dir, 3, MCP23017_TIMEOUT);
    if (mcp23017_status) return;

    // set pull-up
    const uint8_t pullup[] = { GPPUA, 0b00000000, 0b11111111 };
    mcp23017_status = i2c_transmit(MCP23017_ADDR, pullup, 3, MCP23017_TIMEOUT);
    if (mcp23017_status) return;

    // set all outputs high
    const uint8_t output[] = { GPIOA, 0b11111111 };
    mcp23017_status = i2c_transmit(MCP23017_ADDR, output, 2, MCP23017_TIMEOUT);
}



uint8_t mcp23017_read_port(void) {
    uint8_t data = 0xFF;
    // reading GPIOB (column port) since in mcp23017's sequential mode
    // it is addressed directly after writing to GPIOA in select_row()
    mcp23017_status = i2c_receive(MCP23017_ADDR, &data, 1, MCP23017_TIMEOUT);
    return data;
}


void mcp23017_write_port(uint8_t data) {
    const uint8_t port[] = { GPIOA, data };
    mcp23017_status = i2c_transmit(MCP23017_ADDR, port, 2, MCP23017_TIMEOUT);
}
