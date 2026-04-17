#include "main.h"

/**
 * print_unsigned - prints unsigned with modifiers
 * @l: arguments
 * @mod: modifier
 * Return: count
 */
int print_unsigned(va_list l, char mod)
{
	unsigned long int n;
	unsigned long int div = 1;
	int count = 0;

	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);

	while (n / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}
	return (count);
}

/**
 * print_octal - prints number in octal
 * @l: va_list arguments
 * @mod: modifier
 * Return: count
 */
int print_octal(va_list l, char mod)
{
	unsigned long int n;
	int a[22];
	int i, count = 0;

	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);

	for (i = 0; i < 22; i++)
	{
		a[i] = n % 8;
		n /= 8;
	}
	for (i = 21; i >= 0; i--)
	{
		if (a[i] > 0 || count > 0 || i == 0)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
