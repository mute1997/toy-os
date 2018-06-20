#include <asm/types.h>

static inline void outb(u8 val, u16 port) {
	__asm__ __volatile__ ("outb %0,%1" : : "a" (val), "Nd" (port));
}

static inline u8 inb(u16 port) {
  u8 ret;
  __asm__ __volatile__("inb %1,%0" : "=a" (ret) : "Nd" (port));
  return ret;
}

static inline void io_wait(void)
{
    __asm__ __volatile__ ( "jmp 1f\n\t"
        "1:jmp 2f\n\t"
        "2:" );
}
