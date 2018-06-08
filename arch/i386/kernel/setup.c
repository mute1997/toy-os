#include <std/string.h>
#include <std/hlt.h>
#include <std/printk.h>
#include <drivers/video.h>
#include <asm/types.h>
#include <proto.h>
#include <trap.h>
#include <grub/multiboot2.h>
#include <mm.h>

extern pd_entry page_directory_[1024];

void setup(u32 magic, u32 addr) {
  if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) printk("invalid magic number");
  if (addr & 7) printk("unaligned mbi");

  printk("page_directory_[0]                : %d", page_directory_[0]);
  printk("(pointer)page_directory_[0]       : 0x%x", &page_directory_[0]);


  // MEMO
  // MAGIC : 0x36d76289
  printk("grub info           0x%x", &addr);
  printk("grub magic          0x%x", magic);

  // setup_heap();
  flush_screen();
  
  intr_init(); /* Initialize PIC */
  prot_init(); /* Initialize GDT, IDT, trap */

  // init_paging(); /* Initialize paging (KERNEL_VIRTUAL_BASE - KERNEL_VIRTUAL_END) */

  // setup_physical_memory(addr); /* fill 1 to physical memory */
  
  hlt();
}
