#include "main.h"

/**
 * print_hex_helper - recursive helper for hex printing
 * @n: number
 * @digits: digit string (lower or upper)
 * Return: count
 */
static int print_hex_helper(unsigned int n, char *digits)
{
	int count = 0;
	char digit;

	if (n >= 16)
		count += print_hex_helper(n / 16, digits);
	digit = digits[n % 16];
	write(1, &digit, 1);
	count++;
	return (count);
}

/**
 * print_hex_lower - prints hex in lowercase
 * @args: va_list
 * Return: count
 */
int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (print_hex_helper(n, "0123456789abcdef"));
}

/**
 * print_hex_upper - prints hex in uppercase
 * @args: va_list
 * Return: count
 */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (print_hex_helper(n, "0123456789ABCDEF"));
}

/**
 * print_octal - prints octal
 * @args: va_list
 * Return: count
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[12];
	int i = 0, count = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = '0' + (n % 8);
		n /= 8;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}

/**
 * print_pointer - prints pointer address
 * @args: va_list
 * Return: count
 */
int print_pointer(va_list args)
{
	unsigned long n = (unsigned long)va_arg(args, void *);
	char *digits = "0123456789abcdef";
	char buffer[20];
	int i = 0, count = 0;

	write(1, "0x", 2);
	count += 2;
	if (n == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	while (n)
	{
		buffer[i++] = digits[n % 16];
		n /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		count++;
	}
	return (count);
}
