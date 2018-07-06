#include <std/stdarg.h>

#define LOG_BUF_SIZE 32768
#define LOG_BUF_LIMIT 25

void setup_log_buf();
void output_log_buf();
int vprintk(const char *fmt, va_list args);
int printk(const char *fmt, ...);
