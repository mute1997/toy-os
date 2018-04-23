#include <std/stdarg.h>
#include <std/string.h>

char *number(char *buf, char*end, unsigned long num) {
  int base = 10;
  char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";
  char *str;
  char *tmp[64];
  int i = 0;

  if (num == 0) {
    tmp[i++] = '0';
  } else {
    while (num > 0) {
      tmp[i++] = digits[num % base];
      num /= base;
    }
  }

  while(i-- > 0) {
    if (buf <= end) *buf = tmp[i];
    ++buf;
  }

  return buf;
}

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
    unsigned int num;
    char *end = buf + size - 1;
    fmt++;
    switch (*fmt) {
      case 'd':
        num = va_arg(args, unsigned int);
        str = number(str, end, num);
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

  return 0; /* TODO printed_lenを返却する */
}
