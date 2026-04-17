#include "main.h"

int handle_hex(unsigned long int n, char *hex, int width)
{
	char a[16];
	int i = 0, count = 0, len = 0;
	unsigned long int temp = n;

	if (temp == 0) len = 1;
	else while (temp > 0) { temp /= 16; len++; }
	
	while (width > len) { count += _putchar(' '); width--; }

	if (temp == 0) return (count + _putchar('0'));

	while (n > 0) {
		a[i++] = hex[n % 16];
		n /= 16;
	}
	for (i = i - 1; i >= 0; i--)
		count += _putchar(a[i]);

	return (count);
}

int print_hex(va_list l, char mod, int width)
{
	unsigned long int n;
	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);
	return (handle_hex(n, "0123456789abcdef", width));
}

int print_HEX(va_list l, char mod, int width)
{
	unsigned long int n;
	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);
	return (handle_hex(n, "0123456789ABCDEF", width));
}
