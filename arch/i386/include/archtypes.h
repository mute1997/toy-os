#include <asm/types.h>

#define GDT_ENTRIES 7

/* GDT table pointer */
struct gdt_ptr {
  u16 limit;
  u32 base;
} __attribute__((packed));

/* Segment descriptor */
struct desc_struct {
  u16 limit_low;
  u16 base_low;
  u8 base_middle;
  u8 access;
  u8 granularity;
  u8 base_high;
} __attribute__((packed));

/* GDT */
struct gdt_page {
  struct desc_struct gdt[GDT_ENTRIES];
};
