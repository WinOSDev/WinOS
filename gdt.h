#ifndef GDT_H
#define GDT_H

#include "stdint.h"

#define GDT_MAX_SIZE 65535
#define SEGMENT_BASE 0
#define SEGMENT_LIMIT 0xFFFFF
#define ACCESS_KERNEL_CODE_RX (0x1<< 7 | set priva | 0x1 << 4 | 0xA)
#define ACCESS_KERNEL_DATA_RW
#define ACCESS_USER_CODE_RX 0xA
#define ACCESS_USER_CODE_RW

typedef struct {
    uint8_t base_high;
    uint8_t flags_limit_high;
    uint8_t access;
    uint8_t base_mid;
    uint16_t base_low;
    uint16_t limit_low;
}__attribute__((packed)) gdt_entry;

typedef struct {
    uint16_t limit;
    uint32_t base;   
}__attribute__((packed)) gdt_table;

gdt_entry gdt_entries[GDT_MAX_SIZE];

void gdt_init();
void gdt_create_entry(uint16_t, uint32_t base,
                        uint32_t limit,
                        uint8_t access,
                        uint8_t flags);

#endif