#include "serial.h"

void serial_init(uint16_t com)
{

    // set DLAB by enabling highest bit in line control register
    // this enables setting baud rate
    outb(LINE_CONTROL_REGISTER(com), ENABLE_DLAB);

    // set baud rate divisor
    outb(DIVISOR_LOW_BYTE(com), BAUD_RATE_DIVISOR & 0x00FF);
    outb(DIVISOR_HIGH_BYTE(com), (BAUD_RATE_DIVISOR & 0xFF00) >> 8);

    // set line control register
    // this sets the highest bit in line control register to 0
    outb(LINE_CONTROL_REGISTER(com), LINE_CONTROL_FLAG);
    outb(FIFO_CONTROL_REGISTER(com), FIFO_CONTROL_FLAG);
    outb(MODEM_CONTROL_REGISTER(com), MODEM_CONTROL_FLAG);

}

static uint8_t is_transmit_empty(uint16_t com)
{
    return inb(LINE_STATUS_REGISTER(com)) & LINE_STATUS_TRANSMIT_STATUS_BIT;
}

void serial_write_byte(uint16_t com, uint8_t data)
{
    while(!is_transmit_empty(com));

    outb(DATA_BUFFER(com), data);
}
