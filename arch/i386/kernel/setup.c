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

  intr_init(); /* Initialize PIC */
  prot_init(); /* Initialize GDT, IDT, trap */
  setup_physical_memory(addr); /* fill 1 to physical memory */

  // For debug
  // ------------------
  extern struct page pages[PHYS_PAGETABLE_SIZE];

  u32 *phys=alloc_page();
  phys=alloc_page();
  phys=alloc_page();
  printk("alloc");
  printk(" page[0]=0x%x count=%d", pages[0].phys_mem, pages[0].count);
  printk(" page[1]=0x%x count=%d", pages[1].phys_mem, pages[1].count);
  printk(" page[2]=0x%x count=%d", pages[2].phys_mem, pages[2].count);

  free_page(phys);
  printk("free");
  printk(" page[0]=0x%x count=%d", pages[0].phys_mem, pages[0].count);
  printk(" page[1]=0x%x count=%d", pages[1].phys_mem, pages[1].count);
  printk(" page[2]=0x%x count=%d", pages[2].phys_mem, pages[2].count);

  // ------------------

  hlt();
}
