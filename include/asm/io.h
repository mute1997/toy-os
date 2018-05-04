void outb(u8 data, unsigned long port) {
  asm volatile("out %0,%1" : : "a" (data), "d" (port));
}
