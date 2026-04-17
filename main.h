#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_int(va_list l, char mod, int width);
int print_str(va_list l, int width);
int print_unsigned(va_list l, char mod, int width);
/* أضيفي بقية النماذج هنا مع معامل width */

#endif
