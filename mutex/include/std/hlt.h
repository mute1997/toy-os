#include <std/printk.h>

static inline void hlt() {
  printk("halting...\n");
  while(1) {
    __asm__ __volatile__ ("hlt");
  }
}
