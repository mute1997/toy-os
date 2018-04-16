#include <drivers/display.h>

void flush_display(void) {
  // TODO: とりあえずなんか表示させたい
  char *p;
  unsigned long i;
  for(i = 0xa0000; i <= 0xaffff; i++){
    p = (char *)i;
    *p = 0;
  }
}
