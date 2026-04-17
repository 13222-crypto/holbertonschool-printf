#include "main.h"

/**
 * handle_hex - helper to print hex
 */
int handle_hex(unsigned long int n, char *hex, int width)
{
	char a[16];
	int i, count = 0, len = 0;
	unsigned long int temp = n;

	if (temp == 0) len = 1;
	else while (temp > 0) { temp /= 16; len++; }
	while (width > len) { count += _putchar(' '); width--; }

	for (i = 0; i < 16; i++) {
		a[i] = hex[n % 16];
		n /= 16;
	}
	for (i = 15; i >= 0; i--) {
		if (a[i] != '0' || count > (width > len ? (count - (width-len)) : 0) || i == 0) {
			_putchar(a[i]);
			count++;
		}
	}
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
