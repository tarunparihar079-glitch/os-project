#ifndef IDT_H
#define IDT_H
#include "types.h"
struct idt_entry_struct {
    uint16_t base_lo;
    uint16_t sel;
    uint8_t  always0;
    uint8_t  flags;
    uint16_t base_hi;
} __attribute__((packed));
void init_idt();
#endif
