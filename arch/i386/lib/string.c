#include <std/printk.h>

void *memset(void *s, int c, int n) {
  unsigned char *ptr = (unsigned char *)s;
  const unsigned char ch = c;
  while (n--) {
    *ptr++ = ch;
  }

  return s;
}

unsigned long strlen(char *s) {
  char *ss;
  for (ss=s;*ss!='\0';ss++);
  return ss - s;
}
