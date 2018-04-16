#include <string.h>
#include <hlt.h>
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

  // TODO: printkを作る
  int i = 0;
  int j = 0;
  put_str(VRAM_MODE, i, j, COLOR_LIGHTGREY, 'X');

  hlt();
}
