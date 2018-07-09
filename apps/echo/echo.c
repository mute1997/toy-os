#include <app/echo.h>
#include <lib/printf.h>

int echo_main(int argc, char *arg[]) {
  int i=1;
  for (int i=1;i<=argc;i++) {
    printf("%s ", arg[i]);
  }
  printf("\n");
}
