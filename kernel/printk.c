#include <drivers/video.h>
#include <std/stdarg.h>

// static char printk_buf[1024];
extern int vsnprintf(char *buf, unsigned long size, const char* fmt, va_list arg);

int vprintk(const char *fmt, va_list args) {
  int printed_len = 0;
  flush_screen();

  // TODO: printk_bufの内容を書き出し

  return printed_len;
}

int printk(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int r = vprintk(fmt, args);
  return r;
}
