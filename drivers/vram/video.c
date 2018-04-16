#include <drivers/video.h>

void flush_screen(void) {
  char *vidptr = (char*)VRAM_MODE;
  for (int i=0;i<100000;i++) {
    vidptr[i] = ' ';
  }
}
