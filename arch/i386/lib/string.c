void *memset(void *s, int c, int n) {
  unsigned char *ptr = (unsigned char *)s;
  const unsigned char ch = c;
  while (n--)
    *ptr++ = ch;

  return s;
}
