#include <std/syscall.h>
#include <std/printk.h>
#include <asm/types.h>

void init_syscalls() {
  for (int i=0;i<600;i++) syscalls[i] = NULL;

  define_syscall(SYS_X, &sys_x);
  define_syscall(SYS_XP, &sys_xp);
  define_syscall(SYS_ECHO, &sys_echo);
  printk("Setup system call... [OK]");
}
