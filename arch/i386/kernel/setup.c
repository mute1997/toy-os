#include <std/string.h>
#include <std/hlt.h>
#include <std/printk.h>
#include <drivers/video.h>
#include <asm/types.h>
#include <proto.h>
#include <trap.h>
#include <grub/multiboot2.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;

void setup_memory() {
  /* initialize bss section */
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

void setup(unsigned long magic, unsigned long addr) {
  struct multiboot_tag *tag;

  setup_memory();
  flush_screen();

  if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) printk("invalid magic number");

  intr_init(); /* Initialize PIC */
  prot_init(); /* Initialize GDT, IDT, trap */

  for (tag = (struct multiboot_tag *) (addr + 8);
       tag->type != MULTIBOOT_TAG_TYPE_END;
       tag = (struct multiboot_tag *) ((multiboot_uint8_t *) tag 
				       + ((tag->size + 7) & ~7))) {
    // printk("Memory lower: %d",((struct multiboot_tag_basic_meminfo *) tag)->mem_lower)
  }

  // software interrupt
  __asm__ __volatile__ ("int3");

  hlt();
}
