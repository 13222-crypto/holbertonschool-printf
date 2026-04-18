#include "main.h"

/**
 * handle_specifier - calls the right handler for a specifier
 * @sp: specifier character
 * @args: va_list
 * @f: flags struct
 * Return: chars printed or -1 if unknown
 */
int handle_specifier(char sp, va_list args, flags_t f)
{
	spec_t specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'p', print_pointer},
		{'b', print_binary},
		{'S', print_S},
		{'r', print_reverse},
		{'R', print_rot13},
		{0, NULL}
	};
	int j = 0;

	while (specs[j].fn)
	{
		if (sp == specs[j].sp)
			return (specs[j].fn(args, f));
		j++;
	}
	return (-1);
}

/**
 * pad - writes n copies of character c
 * @n: count
 * @c: character
 * Return: n
 */
int pad(int n, char c)
{
	int i = 0;

	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (n);
}

/**
 * print_str_len - prints s for len chars
 * @s: string
 * @len: length
 * Return: len
 */
int print_str_len(char *s, int len)
{
	int i = 0;

	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (len);
}

/**
 * numlen_base - returns digit count of n in base
 * @n: number
 * @base: base
 * Return: digit count
 */
int numlen_base(unsigned long n, int base)
{
	int len = 0;

	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
