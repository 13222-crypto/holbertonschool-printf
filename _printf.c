#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string with format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	format_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'%', print_percent},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'p', print_pointer},
		{0, NULL}
	};

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			int j = 0, found = 0;

			i++;
			if (!format[i])
				return (-1);

			while (specifiers[j].handler)
			{
				if (format[i] == specifiers[j].specifier)
				{
					count += specifiers[j].handler(args);
					found = 1;
					break;
				}
				j++;
			}
			if (!found)
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);
	return (count);
}
