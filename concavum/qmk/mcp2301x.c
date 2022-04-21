#include QMK_KEYBOARD_H
#include "i2c_master.h"
#include "mcp2301x.h"


#if defined(__AVR__)
    #define SLEEP_MS(t) _delay_ms(t)
#elif defined(__CHIBIOS__)
    #define SLEEP_MS(t) chThdSleepMilliseconds(t)
#endif


static i2c_status_t mcp2301x_status = I2C_STATUS_ERROR;


void mcp2301x_init(void) {
    mcp2301x_status = I2C_STATUS_SUCCESS;

    SLEEP_MS(MCP2301X_STARTUP_DELAY);
    i2c_init();

    // set pin direction
    const uint8_t pin_dir[] = { IODIRA, 0b11111111, 0b11111111 };
    mcp2301x_status = i2c_transmit(MCP2301X_ADDR, pin_dir, 3, MCP2301X_TIMEOUT);
    if (mcp2301x_status) return;

    // set pull-ups
    const uint8_t pullup[] = { GPPUA, 0b00000000, 0b11111111 };
    mcp2301x_status = i2c_transmit(MCP2301X_ADDR, pullup, 3, MCP2301X_TIMEOUT);
    if (mcp2301x_status) return;

    // set all outputs low
    const uint8_t output[] = { GPIOA, 0b00000000 };
    mcp2301x_status = i2c_transmit(MCP2301X_ADDR, output, 2, MCP2301X_TIMEOUT);
}


uint8_t mcp2301x_read_port(void) {
    uint8_t data = 0xFF;
    uint8_t gpiob = GPIOB;
    // first, set address pointer to GPIOB
    mcp2301x_status = i2c_transmit(MCP2301X_ADDR, &gpiob, 1, MCP2301X_TIMEOUT);
    // read GPIOB (column port)
    mcp2301x_status = i2c_receive(MCP2301X_ADDR, &data, 1, MCP2301X_TIMEOUT);
    return data;
}


void mcp2301x_write_port(uint8_t data) {
    const uint8_t port[] = { IODIRA, data };
    mcp2301x_status = i2c_transmit(MCP2301X_ADDR, port, 2, MCP2301X_TIMEOUT);
}
