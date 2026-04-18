#include "main.h"

/**
 * print_binary - prints binary number
 * @l: va_list
 * @width: width
 * @precision: precision
 * Return: count
 */
int print_binary(va_list l, int width, int precision)
{
	unsigned int n = va_arg(l, unsigned int);
	unsigned int m, i, sum;
	unsigned int a[32];
	int count = 0;

	(void)width;
	(void)precision;

	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			count += _putchar('0' + a[i]);
		}
	}
	return (count);
}
