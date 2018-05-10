#include <std/string.h>
#include <std/hlt.h>
#include <std/printk.h>
#include <drivers/video.h>
#include <asm/types.h>
#include <proto.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;

// TODO protect.cに定義しているのであとで消す
// ------------------------
#define store_idt(dtr) __asm__ __volatile__("sidt %0":"=m" (*dtr))
#define store_gdt(dtr) __asm__ __volatile__("sgdt %0":"=m" (*dtr))
// ------------------------

void setup_memory() {
  /* initialize bss section */
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

void setup() {
  setup_memory();
  flush_screen();

  intr_init(); /* Initialize PIC */
  prot_init(); /* Initialize GDT, IDT, trap */

  __asm__ __volatile__ ("int3");

  hlt();
}
