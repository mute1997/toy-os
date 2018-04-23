#include <asm/types.h>
#include <std/printk.h>
#include <std/string.h>
#include <archtypes.h>

#define load_gdt(dtr) __asm__ __volatile__ ("lgdt %0"::"m"(dtr))
#define init_seg() __asm__ __volatile__ ("\n \
    mov %ax,%ds \n \
    mov %ax,%es \n \
    mov %ax,%fs \n \
    mov %ax,%gs \n \
    mov %ax,%ss \n \
    ")

static struct gdt_ptr kgdt_ptr;
static struct gdt_page kgdt;

/* Init Segment descriptor */
void init_segment(struct desc_struct *desc, u32 base, u32 size) {
  desc->base_low = base;
  desc->base_middle = base >> 16;
  desc->base_high = base >> 24;
  desc->limit_low = size >> 12;
  desc->granularity =  GRANULAR | (size >> (PAGE_GRAN_SHIFT + GRANULARITY_SHIFT)) | DEFAULT;
}

void init_data_segment(struct desc_struct *desc, u32 base, u32 size, int privilege) {
  init_segment(desc, base, size);
  desc->access = (privilege << 5) | (PRESENT | SEGMENT | WRITABLE);
}

void init_code_segment(struct desc_struct *desc, u32 base, u32 size, int privilege) {
  init_segment(desc, base, size);
  desc->access = (privilege << 5) | (PRESENT | SEGMENT | EXECUTABLE | READABLE);
}

void switch_to_new_gdt() {
  load_gdt(kgdt_ptr);
  init_seg();
}

void setup_gdt() {
  printk("Setup gdt...");

  /* Init GDT */
  memset(kgdt.gdt, 0, sizeof(kgdt));

  /* set GDT pointer */
  kgdt_ptr.base = (u32)kgdt.gdt;
  kgdt_ptr.limit = sizeof(kgdt.gdt)-1;

  /* Init GDT segments */
  init_code_segment(&kgdt.gdt[0], 0, 0xFFFFFFFF, KERNEL_PRIVILEGE); /* kernel code */
  init_data_segment(&kgdt.gdt[1], 0, 0xFFFFFFFF, KERNEL_PRIVILEGE); /* kernel data */
  init_code_segment(&kgdt.gdt[2], 0, 0xFFFFFFFF, USER_PRIVILEGE); /* user code */
  init_data_segment(&kgdt.gdt[3], 0, 0xFFFFFFFF, USER_PRIVILEGE);  /* user data */
  init_segment(&kgdt.gdt[4], 0x0, 0); /* unusable LDT */
  kgdt.gdt[4].access = PRESENT | 2;

  /* set new GDT */
  switch_to_new_gdt();

  printk("[OK]");
}
