#include "main.h"

/**
 * _printf - custom printf with width and modifiers
 * @format: string
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, width;
	char mod;

	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			width = 0;
			if (format[i] == '*') {
				width = va_arg(args, int);
				i++;
			} else {
				while (format[i] >= '0' && format[i] <= '9') {
					width = (width * 10) + (format[i] - '0');
					i++;
				}
			}
			mod = 0;
			if (format[i] == 'l' || format[i] == 'h') { mod = format[i]; i++; }
			
			if (format[i] == 'd' || format[i] == 'i') count += print_int(args, mod, width);
			else if (format[i] == 's') count += print_str(args, width);
			else if (format[i] == 'u') count += print_unsigned(args, mod, width);
			else if (format[i] == 'c') {
				int c_val = va_arg(args, int);
				while (width > 1) { count += _putchar(' '); width--; }
				count += _putchar(c_val);
			}
			else if (format[i] == '%') count += _putchar('%');
			else {
				count += _putchar('%');
				if (mod) count += _putchar(mod);
				count += _putchar(format[i]);
			}
		} else count += _putchar(format[i]);
		i++;
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
