#include <std/string.h>
#include <std/hlt.h>
#include <std/printk.h>
#include <drivers/video.h>
#include <asm/types.h>
#include <proto.h>
#include <trap.h>
#include <grub/multiboot2.h>
#include <mm.h>
#include <std/syscall.h>

#include <lib/scanf.h>
#include <lib/echo.h>

void setup(u32 magic, u32 addr) {
  if (magic != MULTIBOOT2_BOOTLOADER_MAGIC) printk("invalid magic number\n");

  init_kern_pages(); /* Init page 3GB to KERNEL_VIRTUAL_END for kernel */

  flush_screen();

  /* setup heap */
  setup_log_buf();
  setup_page_table();

  prot_init(); /* Initialize GDT, IDT, trap */

  setup_physical_memory(addr); /* search free memory by grub info */
  
  intr_init(); /* Initialize PIC */

  init_syscalls(); /* Initialize systemcalls */

  init_keyboard(); /* Initialize keyboard */

  char s[256];
  while (1) {
    memset(s, NULL, sizeof(s));
    scanf(s);
    echo(s);
  }

  hlt();
}
