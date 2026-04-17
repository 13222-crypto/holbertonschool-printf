#include "main.h"

/**
 * print_int - prints integers with width and modifiers
 * @l: arguments
 * @mod: modifier
 * @width: width
 * Return: count
 */
int print_int(va_list l, char mod, int width)
{
	long int n;
	unsigned long int num, temp;
	unsigned long int div = 1;
	int count = 0, len = 0;

	if (mod == 'l') n = va_arg(l, long int);
	else if (mod == 'h') n = (short int)va_arg(l, int);
	else n = va_arg(l, int);

	if (n < 0) { len++; temp = n * -1; }
	else temp = n;

	if (temp == 0) len++;
	else {
		unsigned long int t2 = temp;
		while (t2 > 0) { t2 /= 10; len++; }
	}

	while (width > len) { count += _putchar(' '); width--; }

	if (n < 0) { count += _putchar('-'); num = n * -1; }
	else num = n;

	while (num / div > 9) div *= 10;
	while (div != 0) {
		count += _putchar('0' + (num / div));
		num %= div;
		div /= 10;
	}
	return (count);
}

/**
 * print_str - prints string with width
 * @l: va_list
 * @width: width
 * Return: count
 */
int print_str(va_list l, int width)
{
	char *s = va_arg(l, char *);
	int i, len = 0, count = 0;

	if (!s) s = "(null)";
	while (s[len]) len++;
	while (width > len) { count += _putchar(' '); width--; }
	for (i = 0; s[i]; i++) count += _putchar(s[i]);
	return (count);
}
