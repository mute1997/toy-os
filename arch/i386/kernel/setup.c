#include <std/string.h>
#include <std/hlt.h>
#include <std/printk.h>
#include <drivers/video.h>
#include <asm/types.h>
#include <proto.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;

void setup_memory() {
  /* initialize bss section */
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

void setup() {
  setup_memory();
  flush_screen();

  disable(); /* Disable interrupt */

  intr_init(); /* Initialize PIC */
  prot_init(); /* Initialize GDT, IDT, trap */

  /* TODO 割り込みハンドラをちゃんと書く */
  /* TODO IDTがちゃんと登録されていないみたいで落ちる */
  enable(); /* Enable interrupt */

  hlt();
}
