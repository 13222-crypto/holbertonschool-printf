#include "main.h"

/**
 * print_char - prints a character with width
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_char(va_list args, flags_t f)
{
	char c = (char)va_arg(args, int);
	int count = 0;

	if (!f.minus)
		count += pad(f.width - 1, ' ');
	write(1, &c, 1);
	count++;
	if (f.minus)
		count += pad(f.width - 1, ' ');
	return (count);
}

/**
 * print_string - prints a string with width/precision
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_string(va_list args, flags_t f)
{
	char *str = va_arg(args, char *);
	int len = 0, count = 0, print_len;

	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	print_len = (f.prec >= 0 && f.prec < len) ? f.prec : len;
	if (!f.minus)
		count += pad(f.width - print_len, ' ');
	count += print_str_len(str, print_len);
	if (f.minus)
		count += pad(f.width - print_len, ' ');
	return (count);
}

/**
 * print_percent - prints percent sign
 * @args: va_list (unused)
 * @f: flags (unused)
 * Return: 1
 */
int print_percent(va_list args, flags_t f)
{
	(void)args;
	(void)f;
	write(1, "%", 1);
	return (1);
}

/**
 * print_S - prints string escaping non-printable chars
 * @args: va_list
 * @f: flags (unused)
 * Return: count
 */
int print_S(va_list args, flags_t f)
{
	char *str = va_arg(args, char *);
	int i = 0, count = 0;
	unsigned char c;
	char hex[4];

	(void)f;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (c < 32 || c >= 127)
		{
			hex[0] = '\\';
			hex[1] = 'x';
			hex[2] = "0123456789ABCDEF"[c / 16];
			hex[3] = "0123456789ABCDEF"[c % 16];
			write(1, hex, 4);
			count += 4;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
