#include "main.h"

/**
 * print_int_helper - recursive helper to print integer
 * @n: the number
 * Return: count of characters printed
 */
static int print_int_helper(long n)
{
	int count = 0;
	char digit;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += print_int_helper(n / 10);
	digit = (char)('0' + (n % 10));
	write(1, &digit, 1);
	count++;
	return (count);
}

/**
 * print_int - prints a signed integer
 * @args: va_list of arguments
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);

	return (print_int_helper((long)n));
}

/**
 * print_uint_helper - recursive helper for unsigned int
 * @n: the number
 * Return: count
 */
static int print_uint_helper(unsigned int n)
{
	int count = 0;
	char digit;

	if (n >= 10)
		count += print_uint_helper(n / 10);
	digit = (char)('0' + (n % 10));
	write(1, &digit, 1);
	count++;
	return (count);
}

/**
 * print_unsigned - prints an unsigned integer
 * @args: va_list
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (print_uint_helper(n));
}
