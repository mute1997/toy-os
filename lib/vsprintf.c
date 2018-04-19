#include <std/stdarg.h>
#include <std/string.h>

int vsnprintf(char *buf, unsigned long size, const char *fmt, va_list args) {
  char *str = buf;
  for(;*fmt;fmt++) {
    if (*fmt != '%') {
      *str = *fmt;
      str++;
      continue;
    }

    char *s;
    int len;
    fmt++;
    switch (*fmt) {
      case 'd':
        // strに文字列をいれる
        break;
      case 's':
        s = va_arg(args, char*);
        len = strlen(s);
        for(int i=0;i<len;i++) {
          *str=*s;
          *str++;
          *s++;
        }
        break;
      default:
        ;
    }
  }

  return 0;
}
