#include <std/syscall.h>

int sys_x(u32 addr) {
  printk("sys_x");
  return 0;
}

int sys_xp(u32 addr) {
  printk("sys_xp");
  return 0;
}
