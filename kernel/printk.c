#include <drivers/video.h>
#include <mm.h>
#include <std/stdarg.h>

#define LOG_BUF_SIZE 32768
#define LOG_BUF_LIMIT 25

char log_buf[LOG_BUF_SIZE][256];
unsigned long top = 0;
unsigned long bottom = 0;

extern int vsnprintf(char *buf, unsigned long size, const char *fmt, va_list args);

void setup_log_buf() {
  memset(log_buf, 0, sizeof(log_buf));
}


int vprintk(const char *fmt, va_list args) {
  int printed_len = vsnprintf(log_buf[bottom], sizeof(log_buf[bottom]), fmt, args);

  flush_screen();

  /* output log_buf to screen */
  int lines = bottom - top + 1;
  for(int i=0;i<lines;i++) {
    put_str(VRAM_MODE, 0, i, COLOR_LIGHTGREY, log_buf[top + i]);
  }
  bottom++;

  /* if overflow log_buf, shift top */
  lines = (bottom - top + 1);
  if(lines > LOG_BUF_LIMIT) top++;

  return printed_len;
}

int printk(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int r = vprintk(fmt, args);
  return r;
}
