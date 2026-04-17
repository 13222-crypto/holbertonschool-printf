#include "main.h"

/**
 * print_base - handles octal and hex with the hash (#) flag
 */
int print_base(unsigned int n, int base, int hash, int upper)
{
	char *set = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char buffer[50];
	int i = 0, count = 0;

	if (n == 0)
		return (_putchar('0'));

	if (hash)
	{
		if (base == 8)
			count += _putchar('0');
		else if (base == 16)
		{
			count += _putchar('0');
			count += _putchar(upper ? 'X' : 'x');
		}
	}

	while (n > 0)
	{
		buffer[i++] = set[n % base];
		n /= base;
	}
	while (--i >= 0)
		count += _putchar(buffer[i]);
	return (count);
}

/**
 * print_number - handles %d and %i with + and space flags
 */
int print_number(int n, int plus, int space)
{
	unsigned int n1;
	int count = 0;

	if (n >= 0)
	{
		if (plus) count += _putchar('+');
		else if (space) count += _putchar(' ');
	}
	if (n < 0)
	{
		count += _putchar('-');
		n1 = -n;
	}
	else
		n1 = n;
	return (count + print_number_recursion(n1));
}

int print_number_recursion(unsigned int n1)
{
	int count = 0;
	if (n1 / 10)
		count += print_number_recursion(n1 / 10);
	return (count + _putchar((n1 % 10) + '0'));
}

/**
 * _printf - custom printf function
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, plus, space, hash;

	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			plus = space = hash = 0;
			i++;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+') plus = 1;
				else if (format[i] == ' ') space = 1;
				else if (format[i] == '#') hash = 1;
				i++;
			}
			if (format[i] == '\0') return (-1);
			if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int), plus, space);
			else if (format[i] == 'o')
				count += print_base(va_arg(args, unsigned int), 8, hash, 0);
			else if (format[i] == 'x')
				count += print_base(va_arg(args, unsigned int), 16, hash, 0);
			else if (format[i] == 'X')
				count += print_base(va_arg(args, unsigned int), 16, hash, 1);
			else if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				if (!s) s = "(null)";
				while (s && *s) count += _putchar(*s++);
			}
			else if (format[i] == '%') count += _putchar('%');
			else { count += _putchar('%'); count += _putchar(format[i]); }
		}
		else count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
