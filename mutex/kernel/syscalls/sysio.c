#include <std/syscall.h>
#include <std/printk.h>
#include <std/stdio.h>

extern char key_inputs[256];

int sys_write(int fd, char *buf, u32 count) {
  if (fd == STDOUT) {
    printk("%s", buf);
  }
  return 0;
}

int sys_read(int fd, char *buf, u32 count) {
  if (fd == STDIN) {
    for(int i=0;i<strlen(key_inputs)||i>count;i++) *buf++ = key_inputs[i];
  }
  return 0;
}
