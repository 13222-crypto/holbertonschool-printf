#include "main.h"

/**
 * print_int - prints an integer with precision
 * @args: arguments
 * @params: parameters
 * Return: number of chars printed
 */
int print_int(va_list args, params_t *params)
{
	long n = va_arg(args, int);
	int count = 0, len = 0;
	long temp = (n < 0) ? -n : n;
	char buffer[20];
	int i = 0;

	if (n == 0 && params->precision == 0) return (0);

	/* تحويل الرقم لنص في buffer */
	if (temp == 0) buffer[i++] = '0';
	while (temp > 0)
	{
		buffer[i++] = (temp % 10) + '0';
		temp /= 10;
	}

	if (n < 0) _putchar('-'), count++;

	/* إضافة الأصفار بناءً على الـ precision */
	len = i;
	while (len < (int)params->precision)
	{
		_putchar('0');
		count++;
		len++;
	}

	/* طباعة الرقم من الـ buffer (بالعكس) */
	while (i--)
	{
		_putchar(buffer[i]);
		count++;
	}
	return (count);
}
