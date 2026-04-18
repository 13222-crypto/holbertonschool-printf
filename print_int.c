#include "main.h"

/**
 * write_int - writes padded integer
 * @num: absolute value
 * @neg: 1 if negative
 * @f: flags
 * Return: count
 */
static int write_int(unsigned long num, int neg, flags_t f)
{
	int count = 0, numlen, zeros = 0, spaces = 0;
	char sign = 0;
	char buf[32];
	int i = 0;
	unsigned long tmp = num;

	numlen = numlen_base(num, 10);
	if (num == 0 && f.prec == 0)
		numlen = 0;
	if (neg) sign = '-';
	else if (f.plus) sign = '+';
	else if (f.space) sign = ' ';
	if (f.prec > numlen)
		zeros = f.prec - numlen;
	spaces = f.width - numlen - zeros - (sign ? 1 : 0);
	if (!f.minus && !f.zero)
		count += pad(spaces, ' ');
	if (sign)
	{
		write(1, &sign, 1);
		count++;
	}
	if (!f.minus && f.zero)
		count += pad(spaces, '0');
	count += pad(zeros, '0');
	if (numlen > 0)
	{
		while (tmp > 0)
		{
			buf[i++] = '0' + (tmp % 10);
			tmp /= 10;
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
 * print_int - prints signed integer
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_int(va_list args, flags_t f)
{
	long n;
	int neg = 0;

	if (f.mod == 'l')
		n = va_arg(args, long);
	else if (f.mod == 'h')
		n = (short)va_arg(args, int);
	else
		n = va_arg(args, int);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	return (write_int((unsigned long)n, neg, f));
}
