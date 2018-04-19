#include <std/string.h>
#include <std/hlt.h>
#include <std/printk.h>
#include <drivers/video.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;

void setup_memory() {
  // initialize bss section
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

void setup() {
  setup_memory();
  flush_screen();

  for(int i=0;i<30;i++) {
    printk("1234567", 1);
  }

  hlt();
}
