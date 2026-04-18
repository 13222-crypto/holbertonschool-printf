#include "main.h"

/**
 * parse_flags - parses flags/width/prec/mod from format
 * @fmt: format string after '%'
 * @i: index pointer
 * @args: pointer to va_list for * width/prec
 * Return: flags_t struct
 */
static flags_t parse_flags(const char *fmt, int *i, va_list *args)
{
	flags_t f = {0, 0, 0, 0, 0, 0, -1, 0};

	while (fmt[*i] == '-' || fmt[*i] == '0' || fmt[*i] == '+'
		|| fmt[*i] == ' ' || fmt[*i] == '#')
	{
		if (fmt[*i] == '-') f.minus = 1;
		else if (fmt[*i] == '0') f.zero = 1;
		else if (fmt[*i] == '+') f.plus = 1;
		else if (fmt[*i] == ' ') f.space = 1;
		else if (fmt[*i] == '#') f.hash = 1;
		(*i)++;
	}
	if (fmt[*i] == '*')
	{
		f.width = va_arg(*args, int);
		(*i)++;
	}
	else
	{
		while (fmt[*i] >= '0' && fmt[*i] <= '9')
		{
			f.width = f.width * 10 + (fmt[*i] - '0');
			(*i)++;
		}
	}
	if (fmt[*i] == '.')
	{
		(*i)++;
		f.prec = 0;
		if (fmt[*i] == '*')
		{
			f.prec = va_arg(*args, int);
			(*i)++;
		}
		else
		{
			while (fmt[*i] >= '0' && fmt[*i] <= '9')
			{
				f.prec = f.prec * 10 + (fmt[*i] - '0');
				(*i)++;
			}
		}
	}
	if (fmt[*i] == 'l' || fmt[*i] == 'h')
	{
		f.mod = fmt[*i];
		(*i)++;
	}
	return (f);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, ret;

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
				i++;
				continue;
			}
			else
			{
				flags_t f = parse_flags(format, &i, &args);

				ret = handle_specifier(format[i], args, f);
				if (ret == -1)
				{
					write(1, "%", 1);
					write(1, &format[i], 1);
					count += 2;
				}
				else
					count += ret;
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
