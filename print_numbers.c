#include "main.h"

int print_unsigned(va_list l, char mod, int width)
{
	unsigned long int n, temp;
	unsigned long int div = 1;
	int count = 0, len = 0;

	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);

	temp = n;
	if (temp == 0) len = 1;
	else while (temp > 0) { temp /= 10; len++; }
	while (width > len) { count += _putchar(' '); width--; }

	while (n / div > 9) div *= 10;
	while (div != 0) {
		count += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}
	return (count);
}

int print_octal(va_list l, char mod, int width)
{
	unsigned long int n, temp;
	int a[22], i, count = 0, len = 0;

	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);

	temp = n;
	if (temp == 0) len = 1;
	else while (temp > 0) { temp /= 8; len++; }
	while (width > len) { count += _putchar(' '); width--; }

	for (i = 0; i < 22; i++) { a[i] = n % 8; n /= 8; }
	for (i = 21; i >= 0; i--) {
		if (a[i] > 0 || count > 0 || i == 0) {
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
