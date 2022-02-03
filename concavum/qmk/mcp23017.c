#include QMK_KEYBOARD_H
#include "i2c_master.h"
#include "mcp23017.h"


static i2c_status_t mcp23017_status = I2C_STATUS_ERROR;
bool i2c_initialized = false;


void mcp23017_init(void) {
    mcp23017_status = I2C_STATUS_SUCCESS;

    if (!i2c_initialized) {
        _delay_ms(1000);
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
    }
    i2c_init();  // on pins D(1,0)

    // set pin direction
    mcp23017_status = i2c_start(I2C_ADDR_WRITE, MCP23017_TIMEOUT);  if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(IODIRA, MCP23017_TIMEOUT);          if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(0b01100011, MCP23017_TIMEOUT);      if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(0b11111111, MCP23017_TIMEOUT);      if (mcp23017_status) goto out;
    i2c_stop();

    // set pull-up
    mcp23017_status = i2c_start(I2C_ADDR_WRITE, MCP23017_TIMEOUT);  if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(GPPUA, MCP23017_TIMEOUT);           if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(0b00000000, MCP23017_TIMEOUT);      if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(0b00111111, MCP23017_TIMEOUT);      if (mcp23017_status) goto out;
    i2c_stop();

    // set all outputs high
    mcp23017_status = i2c_start(I2C_ADDR_WRITE, MCP23017_TIMEOUT);  if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(GPIOA, MCP23017_TIMEOUT);           if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(0b11111111, MCP23017_TIMEOUT);
out:
    i2c_stop();
}



uint8_t mcp23017_read_port(void) {
    uint8_t data = 0x00;
    // reading GPIOB (column port) since in mcp23017's sequential mode
    // it is addressed directly after writing to GPIOA in select_row()
    mcp23017_status = i2c_start(I2C_ADDR_READ, MCP23017_TIMEOUT);   if (mcp23017_status) goto out;
    mcp23017_status = i2c_read_nack(MCP23017_TIMEOUT);              if (mcp23017_status < 0) goto out;
    data            = ~(uint8_t)mcp23017_status;
    mcp23017_status = I2C_STATUS_SUCCESS;
out:
    i2c_stop();
    return data;

}


void mcp23017_write_port(uint8_t data) {
    mcp23017_status = i2c_start(I2C_ADDR_WRITE, MCP23017_TIMEOUT);  if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(GPIOA, MCP23017_TIMEOUT);           if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(data, MCP23017_TIMEOUT);
out:
    i2c_stop();
}

    
bool mcp23017_reset_required(void) { return mcp23017_status != I2C_STATUS_SUCCESS; }
