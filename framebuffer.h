/*
The framebuffer has 80 columns and 25 rows

The starting address of the memory-mapped I/O for the framebuffer is 0x000B8000

The memory is divided into 16 bit cell over 2 byte blocks
The higher memory block takes care of color
The lower block takes care of character
Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 | 
Content: | BG         |FG        | Char in ASCII

*/

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "stdint.h"
#include "io.h"

#define FB_START_ADDRESS 0x000B8000

#define FB_HIGH_BYTE_FLAG 14
#define FB_LOW_BYTE_FLAG 15
#define FB_CURSOR_FLAG_PORT 0x3D4
#define FB_CURSOR_DATA_PORT 0x3D5

#define NUM_ROWS 25
#define NUM_COLUMNS 80

typedef enum {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13, 
    LIGHT_BROWN = 14,
    WHITE = 15
} color;

void fb_clear();
void fb_print(const char * buffer_ptr);

// TODO: add write function
// handle scrolling
// handle deletes
// handle etc

#endif