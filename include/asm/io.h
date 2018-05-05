#include <asm/types.h>

static inline void outb(u8 val, u16 port) {
	__asm__ __volatile__ ("outb %0,%1" : : "a" (val), "dN" (port));
}

static inline u8 inb(u16 port) {
  u8 ret;
  __asm__ __volatile__("inb %1,%0" : "=a" (ret) : "d" (port));
  return ret;
}
