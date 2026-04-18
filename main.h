#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_percent(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_pointer(va_list args);
int print_binary(va_list args);
int print_S(va_list args);
int print_reverse(va_list args);
int print_rot13(va_list args);

/**
 * struct format_specifier - struct for format specifiers
 * @specifier: the format character
 * @handler: the function to handle it
 */
typedef struct format_specifier
{
	char specifier;
	int (*handler)(va_list);
} format_t;

#endif /* MAIN_H */
