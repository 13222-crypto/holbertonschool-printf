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

	if (temp == 0) return (count + _putchar('0'));

	for (i = 0; n > 0; i++) {
		a[i] = n % 8;
		n /= 8;
	}
	for (i = i - 1; i >= 0; i--)
		count += _putchar('0' + a[i]);

	return (count);
}
