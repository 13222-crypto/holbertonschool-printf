#include "main.h"

/**
 * print_unsigned - prints an unsigned int
 * @l: va_list arguments
 * Return: count of chars
 */
int print_unsigned(va_list l)
{
	unsigned int n = va_arg(l, unsigned int);
	unsigned int num = n;
	unsigned int div = 1;
	int count = 0;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (count);
}

/**
 * print_octal - prints number in octal
 * @l: va_list arguments
 * Return: count of chars
 */
int print_octal(va_list l)
{
	unsigned int n = va_arg(l, unsigned int);
	int a[11];
	int i, count = 0;

	for (i = 0; i < 11; i++)
	{
		a[i] = n % 8;
		n /= 8;
	}
	for (i = 10; i >= 0; i--)
	{
		if (a[i] > 0 || count > 0 || i == 0)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
