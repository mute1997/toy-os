#include <string.h>

void kernel_main(void) {
  memset();
  while(1) {
    __asm__ __volatile__ ("hlt");
  }
}
