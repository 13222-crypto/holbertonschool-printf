#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @l: va_list arguments from _printf
 *
 * Return: number of characters printed
 */
int print_binary(va_list l)
{
	unsigned int n;
	unsigned int m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(l, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
