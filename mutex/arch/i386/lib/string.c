#include <std/string.h>

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
  int s1_len = strlen(s1);
  int s2_len = strlen(s2);
  if (s1_len != s2_len) return s1_len - s2_len;
  for (int i=0;i<s1_len;i++) {
    if (s1[i] != s2[i]) {
      return -1;
    }
  }
  return 0;
}
