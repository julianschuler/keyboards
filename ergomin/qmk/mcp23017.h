#pragma once

#define IODIRA 0x00
#define IODIRB 0x01
#define GPPUA 0x0C
#define GPPUB 0x0D
#define GPIOA 0x12
#define GPIOB 0x13

#define MCP23017_ADDR (0x20 << 1)
#define MCP23017_TIMEOUT 50


void mcp23017_init(void);
uint8_t mcp23017_read_port(void);
void mcp23017_write_port(uint8_t);
