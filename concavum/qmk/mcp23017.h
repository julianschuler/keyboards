#pragma once

#define IODIRA 0x00
#define IODIRB 0x01
#define GPPUA 0x0C
#define GPPUB 0x0D
#define GPIOA 0x12
#define GPIOB 0x13

#define MCP23017_ADDR 0x20
#define MCP23017_TIMEOUT 100
#define I2C_ADDR_WRITE ((MCP23017_ADDR) << 1)
#define I2C_ADDR_READ ((MCP23017_ADDR) << 1 | 1)

typedef int16_t mcp23017_status_t;

void mcp23017_init(void);
uint8_t mcp23017_read_port(void);
void mcp23017_write_port(uint8_t);

bool mcp23017_reset_required(void);

