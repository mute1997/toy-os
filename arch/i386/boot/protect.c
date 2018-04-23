#include <asm/types.h>
#include <std/printk.h>
#include <archtypes.h>

static struct gdt_ptr kgdt_ptr;
static struct gdt_page kgdt;

/* Init Segment descriptor */
void init_segment(struct desc_struct *desc, u32 base, u32 size) {
  /* TODO: マジックナンバーが多いので修正する */
  desc->base_low = base;
  desc->base_middle = base >> 16;
  desc->base_high = base >> 24;

  /* TODO limit_low */
  // desc->limit_low = 0;

  /* TODO granularity */
  // desc->granularity = 0;
}

void init_data_segment(struct desc_struct *desc, u32 base, u32 size, int privilege) {
  init_segment(desc, base, size);
  /* TODO: access byteの設定*/
}

void init_code_segment(struct desc_struct *desc, u32 base, u32 size, int privilege) {
  init_segment(desc, base, size);
  /* TODO: access byteの設定*/
}

void switch_to_new_gdt() {
}

void setup_gdt() {
  printk("Setup gdt...");

  /* Init GDT */
  // memset(kgdt, 0, sizeof(kgdt));

  /* set GDT pointer */
  kgdt_ptr.base = (u32)kgdt.gdt;
  kgdt_ptr.limit = sizeof(kgdt.gdt)-1;

  /* Init GDT segments */
  /* TODO: unusable LDT */
  init_code_segment(&kgdt.gdt[0], 0x0, 0x0, KERNEL_PRIVILEGE); /* kernel code */
  init_data_segment(&kgdt.gdt[0], 0x0, 0x0, KERNEL_PRIVILEGE); /* kernel data */
  init_code_segment(&kgdt.gdt[0], 0x0, 0x0, USER_PRIVILEGE); /* user code */
  init_data_segment(&kgdt.gdt[0], 0x0, 0x0, USER_PRIVILEGE);  /* user data */

  /* set new GDT */
  switch_to_new_gdt();

  printk("[OK]");
}
