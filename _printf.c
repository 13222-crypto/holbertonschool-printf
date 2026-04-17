#include "main.h"

/**
 * print_hex_p - prints hexadecimal for pointers
 * @n: number
 * Return: count
 */
int print_hex_p(unsigned long int n)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n / 16)
		count += print_hex_p(n / 16);
	count += _putchar(hex[n % 16]);
	return (count);
}

/**
 * print_p - prints address
 * @ptr: pointer
 * Return: count
 */
int print_p(void *ptr)
{
	unsigned long int p = (unsigned long int)ptr;
	int count = 0;

	if (!ptr)
	{
		str = "(nil)";
		while (str[count])
			_putchar(str[count++]);
		return (count);
	}
	count += _putchar('0');
	count += _putchar('x');
	count += print_hex_p(p);
	return (count);
}

/**
 * _printf - produces output
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
			else if (format[i] == 'p') count += print_p(va_arg(args, void *));
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
