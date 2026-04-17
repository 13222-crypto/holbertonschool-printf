#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_binary(va_list l);
int print_unsigned(va_list l);
int print_octal(va_list l);
int print_hex(va_list l);
int print_HEX(va_list l);

#endif
