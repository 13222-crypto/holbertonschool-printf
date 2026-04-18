#include "main.h"

/**
 * print_pointer - prints pointer address
 * @args: va_list
 * @f: flags
 * Return: count
 */
int print_pointer(va_list args, flags_t f)
{
	unsigned long n = (unsigned long)va_arg(args, void *);
	char *digits = "0123456789abcdef";
	char buf[20];
	int i = 0, count = 0, numlen, spaces;

	numlen = (n == 0) ? 1 : numlen_base(n, 16);
	spaces = f.width - numlen - 2;
	if (!f.minus)
		count += pad(spaces, ' ');
	write(1, "0x", 2);
	count += 2;
	if (n == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		unsigned long tmp = n;

		while (tmp > 0)
		{
			buf[i++] = digits[tmp % 16];
			tmp /= 16;
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
 * print_binary - prints unsigned int in binary
 * @args: va_list
 * @f: flags (unused)
 * Return: count
 */
int print_binary(va_list args, flags_t f)
{
	unsigned int n = va_arg(args, unsigned int);
	char buf[32];
	int i = 0, count = 0;

	(void)f;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buf[i++] = '0' + (n % 2);
		n /= 2;
	}
	while (--i >= 0)
	{
		write(1, &buf[i], 1);
		count++;
	}
	return (count);
}

/**
 * print_reverse - prints string reversed
 * @args: va_list
 * @f: flags (unused)
 * Return: count
 */
int print_reverse(va_list args, flags_t f)
{
	char *str = va_arg(args, char *);
	int len = 0, count = 0;

	(void)f;
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	while (--len >= 0)
	{
		write(1, &str[len], 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13 - prints string in ROT13
 * @args: va_list
 * @f: flags (unused)
 * Return: count
 */
int print_rot13(va_list args, flags_t f)
{
	char *str = va_arg(args, char *);
	char *in  = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *out = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0, j, count = 0;
	char c;

	(void)f;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		c = str[i];
		j = 0;
		while (in[j])
		{
			if (c == in[j])
			{
				c = out[j];
				break;
			}
			j++;
		}
		write(1, &c, 1);
		count++;
		i++;
	}
	return (count);
}
