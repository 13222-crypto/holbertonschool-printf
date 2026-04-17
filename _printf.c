#include "main.h"

/**
 * _printf - custom printf function
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0') break;
			if (format[i] == 'c') count += _putchar(va_arg(args, int));
			else if (format[i] == 's') count += print_str(args);
			else if (format[i] == 'd' || format[i] == 'i') count += print_int(args);
			else if (format[i] == 'u') count += print_unsigned(args);
			else if (format[i] == 'o') count += print_octal(args);
			else if (format[i] == 'x') count += print_hex(args);
			else if (format[i] == 'X') count += print_HEX(args);
			else if (format[i] == 'b') count += print_binary(args);
			else if (format[i] == '%') count += _putchar('%');
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
	_putchar(-1);
	va_end(args);
	return (count);
}
