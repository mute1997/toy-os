#include <asm/types.h>

static inline void outb(u8 data, u16 port) {
  asm volatile("outb %0, %1" : : "a" (data), "Nd" (port));
}
