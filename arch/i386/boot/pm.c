#include <asm/types.h>
#include <std/printk.h>

#define GDT_ENTRIES 7

struct gdt_ptr {
  u16 len;
  u32 ptr;
};

struct desc_struct {
  u16 limit0;
  u16 base0;
  u16 base1: 8, type: 4, s: 1, dpl: 2, p: 1;
  u16 limit1: 4, avl: 1, l: 1, d: 1, g: 1, base2: 8;
} __attribute__((packed));

/* GDT */
struct gdt_page {
  struct desc_struct gdt[GDT_ENTRIES];
};

static struct gdt_ptr kgdt_ptr;
static struct gdt_page kgdt;

void gdt_entry_init(u8 flags, u16 base, u16 limit, struct desc_struct *desc) {
  desc->limit0 = limit;
  desc->limit1 = ((limit) >> 16) & 0x0F;
  desc->base0 = base;
  desc->base1 = ((base) >> 16) & 0xFF;
  desc->base2 = ((base) >> 24) & 0xFF;
  desc->type = flags & 0x0F;
  desc->s = (flags >> 4) & 0x01;
  desc->dpl = (flags >> 5) & 0x03;
  desc->p = (flags >> 7) & 0x01;
  desc->avl = (flags >> 12) & 0x01;
  desc->l = (flags >> 13) & 0x01;
  desc->d = (flags >> 14) & 0x01;
  desc->g = (flags >> 15) & 0x01;
}

/* TODO: */
void setup_gdt() {
  printk("Setup gdt...");

  /* Init gdt segments */
  gdt_entry_init(0x0, 0x0, 0x0, &kgdt.gdt[0]);

  printk("[OK]");
}
