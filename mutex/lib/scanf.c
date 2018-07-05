#include <lib/scanf.h>
#include <std/syscall.h>

extern int is_pressed_enter;

int scanf(char *p) {
  int ret, arg = NULL;

  /* TODO fix busy wait */
  /* TODO use syscall return value */
  while (!is_pressed_enter) __asm__ __volatile__ ("hlt");

  syscall(SYS_SCAN, p, arg, arg, ret);

  while (is_pressed_enter) __asm__ __volatile__ ("hlt");
}
