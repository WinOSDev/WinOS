#ifndef IO_H
#define IO_H

#include "stdint.h"

/* writes a byte of data to a port */
void outb(uint16_t port, uint8_t data);

/* reads a byte of data from a port */
uint8_t inb(uint16_t port);

#endif