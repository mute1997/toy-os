#include <std/stdarg.h>

void setup_log_buf();
int vprintk(const char *fmt, va_list args);
int printk(const char *fmt, ...);
