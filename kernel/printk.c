#include <drivers/video.h>
#include <std/stdarg.h>

#define LOG_BUF_SIZE 32768

static char printk_buf[LOG_BUF_SIZE][1024];
// static unsigned long top;
static unsigned long bottom;

extern int vsnprintf(char *buf, unsigned long size, const char* fmt, va_list arg);

int vprintk(const char *fmt, va_list args) {
  // TODO: ここで落ちてるくさい
  int printed_len = vsnprintf(printk_buf[bottom], sizeof(printk_buf[bottom]), fmt, args);

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
