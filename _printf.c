#include "main.h"

/**
 * get_n_len - gets the number of digits in a number
 */
int get_n_len(unsigned int n, int base)
{
	int len = 0;
	if (n == 0) return (1);
	while (n > 0) { n /= base; len++; }
	return (len);
}

/**
 * print_number - handles %d/%i with flags -, +, space, 0, and width
 */
int print_number(int n, int plus, int space, int zero, int minus, int width)
{
	unsigned int n1;
	int count = 0, len = 0, sign = 0;

	if (n < 0) { n1 = -n; sign = 1; }
	else n1 = n;

	len = get_n_len(n1, 10);
	if (sign || plus || space) len++;

	/* If not minus and not zero, print leading spaces */
	if (!minus && !zero && width > len)
		while (width > len++) count += _putchar(' ');

	if (sign) count += _putchar('-');
	else if (plus) count += _putchar('+');
	else if (space) count += _putchar(' ');

	/* If zero flag and no minus, print leading zeros */
	if (zero && !minus && width > len)
		while (width > len++) count += _putchar('0');

	count += print_number_recursion(n1);

	/* If minus flag, print trailing spaces */
	if (minus && width > len)
		while (width > len++) count += _putchar(' ');

	return (count);
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
	int i = 0, count = 0, plus, space, hash, zero, minus, width;

	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			plus = space = hash = zero = minus = width = 0;
			i++;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0' || format[i] == '-')
			{
				if (format[i] == '+') plus = 1;
				else if (format[i] == ' ') space = 1;
				else if (format[i] == '#') hash = 1;
				else if (format[i] == '0') zero = 1;
				else if (format[i] == '-') minus = 1;
				i++;
			}
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = (width * 10) + (format[i] - '0');
				i++;
			}
			if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int), plus, space, zero, minus, width);
			/* ... (يمكن إضافة بقية الحالات هنا بنفس المنطق) */
			else if (format[i] == 'c') count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				if (!s) s = "(null)";
				while (*s) count += _putchar(*s++);
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
