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
extern unsigned long _text_start;
extern unsigned long _text_end;

void setup_memory() {
  /* initialize bss section */
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

void setup(unsigned long magic, unsigned long addr) {
  setup_memory();
  flush_screen();

  if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) printk("invalid magic number");
  if (addr & 7) printk("unaligned mbi");

  intr_init(); /* Initialize PIC */
  prot_init(); /* Initialize GDT, IDT, trap */

  print_memory_map(addr);

  u32 kernel_size = get_kernel_size();
  printk("Kernel size: %x", kernel_size);

  // software interrupt
  // __asm__ __volatile__ ("int3");

  hlt();
}
