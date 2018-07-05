#include <std/syscall.h>
#include <std/printk.h>

extern char key_inputs[256];
extern int is_pressed_enter;

int sys_echo(char *str) {
  printk("%s", str);
  return 0;
}

int sys_scan(char *p) {
  for(int i=0;i<strlen(key_inputs);i++) *p++ = key_inputs[i];
  return 0;
}
