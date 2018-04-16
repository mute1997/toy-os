#include <drivers/display.h>

void flush_display(void) {
  char *vidptr = (char*)0xb8000;
  for (int i=0;i<100000;i++) {
    vidptr[i] = ' ';
  }
}
