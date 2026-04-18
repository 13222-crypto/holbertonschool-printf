#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_str(va_list l, int width, int precision);
int print_int(va_list l, char mod, int width, int precision);
int print_unsigned(va_list l, char mod, int width, int precision);
int print_octal(va_list l, char mod, int width, int precision);
int print_hex(va_list l, char mod, int width, int precision);
int print_HEX(va_list l, char mod, int width, int precision);
int print_rot13(va_list l, int width, int precision);

#endif
