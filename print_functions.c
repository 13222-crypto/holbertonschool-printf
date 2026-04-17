#include "main.h"

/**
 * print_int - prints an integer
 * @l: va_list arguments
 * Return: number of characters printed
 */
int print_int(va_list l)
{
	long int n = va_arg(l, int);
	unsigned int num;
	unsigned int div = 1;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

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
 * print_str - prints a string
 * @l: va_list arguments
 * Return: number of characters printed
 */
int print_str(va_list l)
{
	char *s = va_arg(l, char *);
	int i, count = 0;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
		count += _putchar(s[i]);

	return (count);
}
