#include <std/stdarg.h>

int vsnprintf(char *buf, unsigned long size, const char *fmt, va_list args) {
  // TODO: 初めは%dとかを置き換えない方法で実装する
  // while((*buf++=*fmt++));

  char *str = buf;
  for(;*fmt;fmt++) {
    *str = *fmt;
    str++;
  }

  return 0;
}
