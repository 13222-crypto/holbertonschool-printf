#include "main.h"

/**
 * print_int - prints integers with l and h modifiers
 * @l: arguments
 * @mod: modifier (l, h, or 0)
 * Return: count
 */
int print_int(va_list l, char mod)
{
	long int n;
	unsigned long int num;
	unsigned long int div = 1;
	int count = 0;

	if (mod == 'l') n = va_arg(l, long int);
	else if (mod == 'h') n = (short int)va_arg(l, int);
	else n = va_arg(l, int);

	if (n < 0)
	{
		count += _putchar('-');
		num = n * -1;
	}
	else num = n;

	while (num / div > 9) div *= 10;
	while (div != 0)
	{
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (count);
}

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
