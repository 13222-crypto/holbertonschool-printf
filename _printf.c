#include "main.h"

/**
 * _printf - custom printf function
 * @format: string
 * Return: char count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'u') count += print_unsigned(args);
			else if (format[i] == 'o') count += print_octal(args);
			else if (format[i] == 'x') count += print_hex(args);
			else if (format[i] == 'X') count += print_HEX(args);
			else if (format[i] == 'b') count += print_binary(args);
			else if (format[i] == '%') count += _putchar('%');
			else {
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
