#include <string.h>
#include <hlt.h>
#include <drivers/display.h>

extern unsigned long _bss_start;
extern unsigned long _bss_end;

void setup_memory() {
  // FIXME: bssをクリアすると死ぬ
  // initialize bss section
  // memset((void *)_bss_start, 0x00, _bss_end-_bss_start);
}

void setup() {
  // FIXME: 関数が呼び出されていない
  // stackの初期化周りで何かしらうまく行ってないかも
  setup_memory();

  flush_display();

  hlt();
}
