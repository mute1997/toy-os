#include <lib/echo.h>

int echo(char *str) {
  int ret, arg = NULL;
  syscall(SYS_ECHO, str, arg, arg, ret);
}
