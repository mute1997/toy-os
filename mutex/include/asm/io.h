#include <asm/types.h>

#define read_registers(a, b, c, d) __asm__ __volatile__ ("" \
      : "=a" (a), "=b" (b), "=c" (c), "=d" (d))

static inline void outb(u16 port, u8 val) {
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
