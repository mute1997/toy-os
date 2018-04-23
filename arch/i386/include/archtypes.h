#include <asm/types.h>

#define GDT_ENTRIES 7

#define GRANULARITY_SHIFT 16
#define PAGE_GRAN_SHIFT 12
#define DEFAULT 0x40

/* GDT access byte */
#define PRESENT 0x80
#define SEGMENT 0x10
#define EXECUTABLE 0x08
#define DIRECTION 0x04
#define READABLE 0x02
#define WRITABLE 0x02
#define ACCESS 0x01

/* GDT Granularity byre */
#define GRANULAR 0x80

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
