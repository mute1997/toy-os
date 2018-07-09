#include <lib/scanf.h>
#include <std/syscall.h>
#include <std/stdio.h>

extern int is_pressed_enter;

int scanf(char *p) {
  int ret, arg = NULL, stdin = STDIN, count = sizeof(char)*256;

  /* TODO fix busy wait */
  /* TODO use syscall return value */
  while (!is_pressed_enter) __asm__ __volatile__ ("hlt");

  syscall(SYS_READ, stdin, p, count, ret);

  while (is_pressed_enter) __asm__ __volatile__ ("hlt");
}
