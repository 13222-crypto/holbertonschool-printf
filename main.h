#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);

/**
 * struct flags_s - holds all format flags
 * @minus: left-align flag
 * @zero: zero-pad flag
 * @plus: force sign flag
 * @space: space flag
 * @hash: hash flag
 * @width: field width
 * @prec: precision (-1 = not set)
 * @mod: length modifier (l, h, or 0)
 */
typedef struct flags_s
{
	int minus;
	int zero;
	int plus;
	int space;
	int hash;
	int width;
	int prec;
	char mod;
} flags_t;

int handle_specifier(char sp, va_list args, flags_t f);
int print_char(va_list args, flags_t f);
int print_string(va_list args, flags_t f);
int print_percent(va_list args, flags_t f);
int print_S(va_list args, flags_t f);
int print_int(va_list args, flags_t f);
int print_unsigned(va_list args, flags_t f);
int print_octal(va_list args, flags_t f);
int print_hex_lower(va_list args, flags_t f);
int print_hex_upper(va_list args, flags_t f);
int print_pointer(va_list args, flags_t f);
int print_binary(va_list args, flags_t f);
int print_reverse(va_list args, flags_t f);
int print_rot13(va_list args, flags_t f);
int pad(int n, char c);
int print_str_len(char *s, int len);
int numlen_base(unsigned long n, int base);

/**
 * struct specifier_s - maps specifier char to handler
 * @sp: specifier character
 * @fn: handler function
 */
typedef struct specifier_s
{
	char sp;
	int (*fn)(va_list, flags_t);
} spec_t;

#endif /* MAIN_H */
