#include "main.h"

int handle_hex(unsigned long int n, char *hex, int width, int prec)
{
	int a[20], i = 0, count = 0, len = 0, zeros = 0;
	unsigned long int temp = n;

	if (n == 0 && prec != 0) len = 1;
	else while (temp > 0) { temp /= 16; len++; }

	if (prec > len) zeros = prec - len;
	if (n == 0 && prec == 0) len = 0;

	while (width > (len + zeros)) { count += _putchar(' '); width--; }
	while (zeros-- > 0) count += _putchar('0');

	if (len > 0) {
		if (n == 0) count += _putchar('0');
		else {
			while (n > 0) { a[i++] = n % 16; n /= 16; }
			for (i--; i >= 0; i--) count += _putchar(hex[a[i]]);
		}
	}
	return (count);
}

int print_hex(va_list l, char mod, int width, int prec)
{
	unsigned long int n;
	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);
	return (handle_hex(n, "0123456789abcdef", width, prec));
}

int print_HEX(va_list l, char mod, int width, int prec)
{
	unsigned long int n;
	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);
	return (handle_hex(n, "0123456789ABCDEF", width, prec));
}
