#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_number(int n, int plus, int space, int zero, int width);
int print_number_recursion(unsigned int n1);
int print_base(unsigned int n, int base, int hash, int upper);

#endif
