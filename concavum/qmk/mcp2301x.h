#pragma once

#define IODIRA 0x00
#define IODIRB 0x01
#define GPPUA 0x0C
#define GPPUB 0x0D
#define GPIOA 0x12
#define GPIOB 0x13

#define MCP2301X_ADDR (0x20 << 1)
#define MCP2301X_TIMEOUT 50
#define MCP2301X_STARTUP_DELAY 1000


void mcp2301x_init(void);
uint8_t mcp2301x_read_port(void);
void mcp2301x_write_port(uint8_t);
