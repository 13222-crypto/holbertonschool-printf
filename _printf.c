#include "main.h"

/**
 * print_hex_custom - prints hex value for non-printable characters
 * @n: character value
 * Return: number of characters printed
 */
int print_hex_custom(unsigned char n)
{
	char *hex = "0123456789ABCDEF";
	int count = 0;

	count += _putchar('\\');
	count += _putchar('x');
	count += _putchar(hex[n / 16]);
	count += _putchar(hex[n % 16]);
	return (count);
}

/**
 * print_S - prints the string with non-printable characters handled
 * @str: string to print
 * Return: count of characters printed
 */
int print_S(char *str)
{
	int i = 0, count = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			count += print_hex_custom(str[i]);
		else
			count += _putchar(str[i]);
		i++;
	}
	return (count);
}

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
			if (format[i] == '\0') return (-1);
			if (format[i] == 'c') count += _putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str) str = "(null)";
				while (str && *str) count += _putchar(*str++);
			}
			else if (format[i] == '%') count += _putchar('%');
			else if (format[i] == 'd' || format[i] == 'i') count += print_number(va_arg(args, int));
			else if (format[i] == 'S') count += print_S(va_arg(args, char *));
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
