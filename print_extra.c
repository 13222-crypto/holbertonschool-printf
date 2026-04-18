#include "main.h"

/**
 * print_binary - prints unsigned int in binary
 * @args: va_list
 * Return: count
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[32];
	int i = 0, count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = '0' + (n % 2);
		n /= 2;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}

/**
 * print_reverse - prints string in reverse
 * @args: va_list
 * Return: count
 */
int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0, count = 0;

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
 * print_rot13 - prints string encoded in ROT13
 * @args: va_list
 * Return: count
 */
int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	char *in  = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *out = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0, j, count = 0;
	char c;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		j = 0;
		c = str[i];
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
