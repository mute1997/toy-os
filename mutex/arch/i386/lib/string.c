#include <std/string.h>
#include <asm/types.h>

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

int strcmp(const char *s1, const char *s2) {
  int i = 0;
  while (s1[i] != NULL || s2[i] != NULL) {
    if (s1[i] != s2[i]) {
      // TODO 0以外を返すとpagefaultになる
      return 2;
    }
    i++;
  }
  return 0;
}
