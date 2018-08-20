#include "framebuffer.h"

static uint16_t *fb_ptr = (uint16_t*) FB_START_ADDRESS;
static uint16_t current_index = 0;

static void fb_write_byte(uint16_t cell_index,
                            uint8_t character,
                            color fg_color,
                            color bg_color)
{
    uint16_t value;

    value = (bg_color << 12 | fg_color << 8 | character );

    fb_ptr[cell_index] = value;
}

static void fb_move_cursor(uint16_t cell_index)
{
    uint8_t high_byte;
    uint8_t low_byte;

    high_byte = (cell_index >> 8) & 0x00FF;
    low_byte = cell_index & 0x00FF;

    outb(FB_CURSOR_FLAG_PORT, FB_HIGH_BYTE_FLAG);
    outb(FB_CURSOR_DATA_PORT, high_byte);

    outb(FB_CURSOR_FLAG_PORT, FB_LOW_BYTE_FLAG);
    outb(FB_CURSOR_DATA_PORT, low_byte);
}

void fb_clear()
{
    for(uint16_t row = 0; row<NUM_ROWS; row++){
        for(uint16_t col = 0; col < NUM_COLUMNS; col++){
            uint16_t index = (row)*NUM_COLUMNS+col;
            fb_write_byte(index, 0, BLACK, BLACK);
        }
    }
}

void fb_print(const char * buffer_ptr)
{
    while(*buffer_ptr)
    {
        fb_write_byte(current_index, 
                        *buffer_ptr,
                        GREEN,
                        BLACK);
        current_index ++;
        buffer_ptr ++;
    }
    fb_move_cursor(current_index);
}