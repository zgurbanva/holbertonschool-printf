 #ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int _putchar(char c);
int _puts(const char *str);

#endif
