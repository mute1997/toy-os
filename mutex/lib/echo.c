#include <lib/echo.h>

void echo(char *str) {
  int ret, arg = NULL;
  syscall(SYS_ECHO, str, arg, arg, ret);
}
