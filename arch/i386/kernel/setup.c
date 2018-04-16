#include <string.h>
#include <hlt.h>
#include <drivers/display.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;

void setup_memory() {
  // initialize bss section
  memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

void setup() {
  setup_memory();

  flush_display();

  hlt();
}
