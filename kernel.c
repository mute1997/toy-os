#include "multiboot.h"

void main(void) {
  unsigned short *screen = (unsigned short *)0xB8000;
  char *msg = "kernel";
  char ch;

  while((ch=*msg++))
    *screen++ = ((0x0F)<<8 | ch);

  while(1);
}
