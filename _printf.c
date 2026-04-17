#include "main.h"

/**
 * print_number - prints an integer with flags
 * @n: number
 * @plus: + flag
 * @space: space flag
 * Return: number of chars printed
 */
int print_number(int n, int plus, int space)
{
	unsigned int n1;
	int count = 0;

	if (n >= 0)
	{
		if (plus)
			count += _putchar('+');
		else if (space)
			count += _putchar(' ');
	}

	if (n < 0)
	{
		count += _putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		count += print_number_recursion(n1 / 10);

	count += _putchar((n1 % 10) + '0');
	return (count);
}

/**
 * print_number_recursion - helper for recursion without re-printing flags
 * @n1: unsigned int
 * Return: count
 */
int print_number_recursion(unsigned int n1)
{
	int count = 0;
	if (n1 / 10)
		count += print_number_recursion(n1 / 10);
	count += _putchar((n1 % 10) + '0');
	return (count);
}

/**
 * _printf - formatted output conversion
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int plus, space;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			plus = 0;
			space = 0;
			i++;
			/* Check for flags */
			while (format[i] == '+' || format[i] == ' ')
			{
				if (format[i] == '+') plus = 1;
				if (format[i] == ' ') space = 1;
				i++;
			}
			/* Handle specifiers */
			if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int), plus, space);
			else if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				if (!s) s = "(null)";
				while (*s) count += _putchar(*s++);
			}
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
