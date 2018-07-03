#include <std/string.h>
#include <std/hlt.h>
#include <std/printk.h>
#include <drivers/video.h>
#include <asm/types.h>
#include <proto.h>
#include <trap.h>
#include <grub/multiboot2.h>
#include <mm.h>

void setup(u32 magic, u32 addr) {
  if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) printk("invalid magic number");

  init_kern_pages(); /* Init page 3GB to KERNEL_VIRTUAL_END for kernel */

  flush_screen();

  /* setup heap */
  setup_log_buf();
  setup_page_table();

  prot_init(); /* Initialize GDT, IDT, trap */

  setup_physical_memory(addr); /* search free memory by grub info */
  
  intr_init(); /* Initialize PIC */

  hlt();
}