#include "main.h"

/**
 * print_hex - prints in lowercase hex
 * @l: va_list
 * @mod: modifier
 * Return: count
 */
int print_hex(va_list l, char mod)
{
	unsigned long int n;
	char a[16];
	int i, count = 0;
	char hex[] = "0123456789abcdef";

	if (mod == 'l')
		n = va_arg(l, unsigned long int);
	else if (mod == 'h')
		n = (unsigned short int)va_arg(l, unsigned int);
	else
		n = va_arg(l, unsigned int);

	for (i = 0; i < 16; i++)
	{
		a[i] = hex[n % 16];
		n /= 16;
	}
	for (i = 15; i >= 0; i--)
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
 * @mod: modifier
 * Return: count
 */
int print_HEX(va_list l, char mod)
{
	unsigned long int n;
	char a[16];
	int i, count = 0;
	char hex[] = "0123456789ABCDEF";

	if (mod == 'l')
		n = va_arg(l, unsigned long int);
	else if (mod == 'h')
		n = (unsigned short int)va_arg(l, unsigned int);
	else
		n = va_arg(l, unsigned int);

	for (i = 0; i < 16; i++)
	{
		a[i] = hex[n % 16];
		n /= 16;
	}
	for (i = 15; i >= 0; i--)
	{
		if (a[i] != '0' || count > 0 || i == 0)
		{
			_putchar(a[i]);
			count++;
		}
	}
	return (count);
}
