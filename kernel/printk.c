#include <drivers/video.h>
#include <std/stdarg.h>

#define LOG_BUF_SIZE 32768

static char *log_buf[LOG_BUF_SIZE];
static unsigned long top = 0;
static unsigned long bottom = 0;

extern int vsnprintf(char *buf, unsigned long size, const char *fmt, va_list args);

int vprintk(const char *fmt, va_list args) {
  int printed_len = vsnprintf(log_buf[bottom], sizeof(log_buf[bottom]), fmt, args);

  flush_screen();

  put_str(VRAM_MODE, 0, 0, COLOR_LIGHTGREY, (char*)1);
  // TODO: printk_bufの内容を書き出し
  int lines = bottom - top + 1;
  for (int i=0;i<lines;i++) {
    // put_str(VRAM_MODE, i, 0, COLOR_LIGHTGREY, 'A');
  }

  return printed_len;
}

int printk(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int r = vprintk(fmt, args);
  return r;
}
