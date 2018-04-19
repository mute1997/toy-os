#include <drivers/video.h>

void flush_screen(void) {
  char *screen_ptr = (char*)VRAM_MODE;
  // 25 line, 80 column
  for (int i=0;i<80*25*2;i+=2) {
    screen_ptr[i] = ' ';
    screen_ptr[i+1] = COLOR_LIGHTGREY;
  }
}

void put_str(int mode, int x, int y, int color, char *s) {
  int column = 80;
  int index = x*2+y*column*2;
  char *screen_ptr = (char*)mode;

  for (;*s;s++) {
    screen_ptr[index] = *s;
    screen_ptr[index+1] = color;
    index+=2;
  }
}
