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
  if (addr & 7) printk("unaligned mbi");

  setup_heap();
  flush_screen();
  
  prot_init(); /* Initialize GDT, IDT, trap */
  intr_init(); /* Initialize PIC */

  // setup_physical_memory(addr); /* fill 1 to physical memory */ /* FIXME */
  
  // u32 *a = MEMORY_HIGH_LIMIT;
  // *a = 1;
  
  hlt();
}
