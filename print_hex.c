#include "main.h"

/**
 * print_hex - prints in lowercase hex
 * @l: va_list
 * Return: count
 */
int print_hex(va_list l)
{
	unsigned int n = va_arg(l, unsigned int);
	char a[8];
	int i, count = 0;
	char hex[] = "0123456789abcdef";

	for (i = 0; i < 8; i++)
	{
		a[i] = hex[n % 16];
		n /= 16;
	}
	for (i = 7; i >= 0; i--)
	{
		if (a[i] != '0' || count > 0 || i == 0)
		{
			_putchar(a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_HEX - prints in uppercase hex
 * @l: va_list
 * Return: count
 */
int print_HEX(va_list l)
{
	unsigned int n = va_arg(l, unsigned int);
	char a[8];
	int i, count = 0;
	char hex[] = "0123456789ABCDEF";

	for (i = 0; i < 8; i++)
	{
		a[i] = hex[n % 16];
		n /= 16;
	}
	for (i = 7; i >= 0; i--)
	{
		if (a[i] != '0' || count > 0 || i == 0)
		{
			_putchar(a[i]);
			count++;
		}
	}
	return (count);
}
