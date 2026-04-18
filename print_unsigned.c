#include "main.h"

/**
 * write_uint - writes unsigned number in given base
 * @num: number
 * @digits: digit charset
 * @base: base
 * @f: flags
 * @prefix: prefix string (e.g. "0x") or NULL
 * Return: count
 */
static int write_uint(unsigned long num, char *digits,
	int base, flags_t f, char *prefix)
{
	int count = 0, numlen, zeros = 0, spaces = 0, plen = 0;
	char buf[64];
	int i = 0;
	unsigned long tmp = num;

	if (prefix && f.hash && num != 0)
	{
		while (prefix[plen])
			plen++;
	}
	numlen = numlen_base(num, base);
	if (num == 0 && f.prec == 0)
		numlen = 0;
	if (f.prec > numlen)
		zeros = f.prec - numlen;
	spaces = f.width - numlen - zeros - plen;
	if (!f.minus && !f.zero)
		count += pad(spaces, ' ');
	if (plen)
		count += print_str_len(prefix, plen);
	if (!f.minus && f.zero)
		count += pad(spaces, '0');
	count += pad(zeros, '0');
	if (numlen > 0)
	{
		while (tmp > 0)
		{
			buf[i++] = digits[tmp % base];
			tmp /= base;
		}
		while (--i >= 0)
		{
			write(1, &buf[i], 1);
			count++;
		}
	}
	if (f.minus)
		count += pad(spaces, ' ');
	return (count);
}

/**
 * print_unsigned - prints unsigned int
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_unsigned(va_list args, flags_t f)
{
	unsigned long n;

	if (f.mod == 'l') n = va_arg(args, unsigned long);
	else if (f.mod == 'h') n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);
	return (write_uint(n, "0123456789", 10, f, NULL));
}

/**
 * print_octal - prints octal
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_octal(va_list args, flags_t f)
{
	unsigned long n;

	if (f.mod == 'l') n = va_arg(args, unsigned long);
	else if (f.mod == 'h') n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);
	return (write_uint(n, "01234567", 8, f, "0"));
}

/**
 * print_hex_lower - prints hex lowercase
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_hex_lower(va_list args, flags_t f)
{
	unsigned long n;

	if (f.mod == 'l') n = va_arg(args, unsigned long);
	else if (f.mod == 'h') n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);
	return (write_uint(n, "0123456789abcdef", 16, f, "0x"));
}

/**
 * print_hex_upper - prints hex uppercase
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_hex_upper(va_list args, flags_t f)
{
	unsigned long n;

	if (f.mod == 'l') n = va_arg(args, unsigned long);
	else if (f.mod == 'h') n = (unsigned short)va_arg(args, unsigned int);
	else n = va_arg(args, unsigned int);
	return (write_uint(n, "0123456789ABCDEF", 16, f, "0X"));
}
