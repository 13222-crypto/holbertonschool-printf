#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_number(long n, int plus, int space, int zero, int minus, int width, int precision);
int print_base(unsigned long n, int base, int hash, int upper, int zero, int minus, int width, int precision);
int print_S(char *s);
int print_rev(char *s);
int print_rot13(char *s);
int print_address(void *p, int minus, int width);

#endif
