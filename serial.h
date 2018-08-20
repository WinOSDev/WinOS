#ifndef SERIAL_H
#define SERIAL_H

#include "stdint.h"
#include "io.h"

#define COM1_BASE_PORT 0x3F8

// highest bit in line control register must be 1
#define DIVISOR_LOW_BYTE(base) base
#define DIVISOR_HIGH_BYTE(base) (base+1)

// highest bit in line control register must be 0
#define DATA_BUFFER(base) base
#define INTERRUPT_ENABLE_REGISTER(base) (base+1)

// irrelevant of DLAB
#define INTERRUPT_IDENTIFICATION_REGISTER(base) (base+2)
#define FIFO_CONTROL_REGISTER(base) (base + 2)
#define LINE_CONTROL_REGISTER(base) (base + 3)
#define MODEM_CONTROL_REGISTER(base) (base + 4)
#define LINE_STATUS_REGISTER(base) (base + 5)

#define ENABLE_DLAB 0x80
#define BAUD_RATE_DIVISOR 0x03
#define LINE_CONTROL_FLAG 0x03
#define FIFO_CONTROL_FLAG 0xc7
#define MODEM_CONTROL_FLAG 0x03

#define LINE_STATUS_TRANSMIT_STATUS_BIT 0x20

void serial_init(uint16_t com);

void serial_write_byte(uint16_t com, uint8_t data);

#endif