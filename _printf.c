#include "main.h"

/**
 * get_n_len - gets the number of digits/chars in an unsigned number
 */
int get_n_len(unsigned int n, int base)
{
	int len = 0;
	if (n == 0) return (1);
	while (n > 0) { n /= base; len++; }
	return (len);
}

/**
 * print_base - handles u, o, x, X with flags and width
 */
int print_base(unsigned int n, int base, int hash, int upper, int zero, int width)
{
	char *set = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char buffer[50];
	int i = 0, count = 0, len = 0;

	len = get_n_len(n, base);
	if (hash && n != 0)
	{
		if (base == 8) len++;
		else if (base == 16) len += 2;
	}

	if (zero && width > len)
		while (width > len++) count += _putchar('0');

	if (n == 0) return (count + _putchar('0'));

	if (hash)
	{
		if (base == 8) count += _putchar('0');
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
	while (--i >= 0) count += _putchar(buffer[i]);
	return (count);
}

int print_number(int n, int plus, int space, int zero, int width)
{
	unsigned int n1;
	int count = 0, len = 0, sign = 0;

	if (n < 0) { n1 = -n; sign = 1; }
	else n1 = n;

	len = get_n_len(n1, 10);
	if (sign || plus || space) len++;

	if (zero && width > len)
	{
		if (sign) count += _putchar('-');
		else if (plus) count += _putchar('+');
		else if (space) count += _putchar(' ');
		while (width > len++) count += _putchar('0');
		return (count + print_number_recursion(n1));
	}
	if (sign) count += _putchar('-');
	else if (plus) count += _putchar('+');
	else if (space) count += _putchar(' ');
	return (count + print_number_recursion(n1));
}

int print_number_recursion(unsigned int n1)
{
	int count = 0;
	if (n1 / 10) count += print_number_recursion(n1 / 10);
	return (count + _putchar((n1 % 10) + '0'));
}

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, plus, space, hash, zero, width;

	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			plus = space = hash = zero = width = 0;
			i++;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0')
			{
				if (format[i] == '+') plus = 1;
				else if (format[i] == ' ') space = 1;
				else if (format[i] == '#') hash = 1;
				else if (format[i] == '0') zero = 1;
				i++;
			}
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = (width * 10) + (format[i] - '0');
				i++;
			}
			if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int), plus, space, zero, width);
			else if (format[i] == 'u') count += print_base(va_arg(args, unsigned int), 10, 0, 0, zero, width);
			else if (format[i] == 'o') count += print_base(va_arg(args, unsigned int), 8, hash, 0, zero, width);
			else if (format[i] == 'x') count += print_base(va_arg(args, unsigned int), 16, hash, 0, zero, width);
			else if (format[i] == 'X') count += print_base(va_arg(args, unsigned int), 16, hash, 1, zero, width);
			else if (format[i] == 'c') count += _putchar(va_arg(args, int));
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
