#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int n1;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		count += print_number(n1 / 10);

	count += _putchar((n1 % 10) + '0');
	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;
	char *str;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				while (*str)
					count += _putchar(*str++);
			}
			else if (format[i] == '%' )
				count += _putchar('%');
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_number(va_arg(args, int));
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
