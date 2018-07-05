#include <std/syscall.h>
#include <std/printk.h>

int sys_echo(char *str) {
  printk("%s", str);
  return 0;
}
