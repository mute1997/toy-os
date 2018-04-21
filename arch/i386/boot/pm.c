#include <asm/types.h>
#include <std/printk.h>

#define GDT_ENTRIES 7

struct desc_struct {
  union {
    /* Segment pointer */
    struct {
      u16 len;
      u32 ptr;
    };

    /* Segment Descriptor */
    struct {
      u16 limit0;
      u16 base0;
      u16 base1: 8, type: 4, s: 1, dpl: 2, p: 1;
      u16 limit1: 4, avl: 1, l: 1, d: 1, g: 1, base2: 8;
    };
  };
} __attribute__((packed));

/* GDT */
struct gdt_page {
  struct desc_struct gdt[GDT_ENTRIES];
};

static struct gdt_page gdt;

void gdt_entry_init(u8 flags, u16 base, u16 limit, struct gdt_page *desc) {
  /* TODO: */
}

void setup_gdt() {
  /* TODO: */
  printk("Setup gdt...");
}
