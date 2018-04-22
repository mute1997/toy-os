#include <asm/types.h>
#include <std/printk.h>

#define GDT_ENTRIES 7

struct gdt_ptr {
  u16 len;
  u32 ptr;
};

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

static struct gdt_ptr kgdt_ptr;
static struct gdt_page kgdt;

void gdt_entry_init() {
}

/* TODO: */
void setup_gdt() {
  printk("Setup gdt...");

  /* Init gdt segments */
  /* kernel code */
  /* kernel data */
  /* user code */
  /* user data */

  printk("[OK]");
}
