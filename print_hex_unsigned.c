#include "main.h"

int print_unsigned(va_list l, char mod, int width, int prec) {
	unsigned long int n = (mod == 'l') ? va_arg(l, unsigned long int) : (mod == 'h' ? (unsigned short int)va_arg(l, unsigned int) : va_arg(l, unsigned int));
	unsigned long int temp = n, div = 1;
	int count = 0, len = 0, zeros = 0;
	if (n == 0 && prec != 0) len = 1;
	while (temp > 0) { temp /= 10; len++; }
	if (prec > len) zeros = prec - len;
	if (n == 0 && prec == 0) len = 0;
	while (width-- > (len + zeros)) count += _putchar(' ');
	while (zeros-- > 0) count += _putchar('0');
	if (len > 0) {
		temp = n; while (temp / div > 9) div *= 10;
		while (div != 0) { count += _putchar('0' + (temp / div)); temp %= div; div /= 10; }
	}
	return (count);
}

int print_octal(va_list l, char mod, int width, int prec) {
	unsigned long int n = (mod == 'l') ? va_arg(l, unsigned long int) : (mod == 'h' ? (unsigned short int)va_arg(l, unsigned int) : va_arg(l, unsigned int));
	unsigned long int temp = n;
	int a[22], i = 0, count = 0, len = 0, zeros = 0;
	if (n == 0 && prec != 0) len = 1;
	while (temp > 0) { temp /= 8; len++; }
	if (prec > len) zeros = prec - len;
	if (n == 0 && prec == 0) len = 0;
	while (width-- > (len + zeros)) count += _putchar(' ');
	while (zeros-- > 0) count += _putchar('0');
	if (len > 0) {
		if (n == 0) count += _putchar('0');
		else {
			while (n > 0) { a[i++] = n % 8; n /= 8; }
			for (i--; i >= 0; i--) count += _putchar('0' + a[i]);
		}
	}
	return (count);
}

int print_hex(va_list l, char mod, int width, int prec) {
	unsigned long int n = (mod == 'l') ? va_arg(l, unsigned long int) : (mod == 'h' ? (unsigned short int)va_arg(l, unsigned int) : va_arg(l, unsigned int));
	int a[20], i = 0, count = 0, len = 0, zeros = 0;
	char *hex = "0123456789abcdef";
	unsigned long int temp = n;
	if (n == 0 && prec != 0) len = 1;
	else while (temp > 0) { temp /= 16; len++; }
	if (prec > len) zeros = prec - len;
	if (n == 0 && prec == 0) len = 0;
	while (width-- > (len + zeros)) count += _putchar(' ');
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

int print_HEX(va_list l, char mod, int width, int prec) {
	unsigned long int n = (mod == 'l') ? va_arg(l, unsigned long int) : (mod == 'h' ? (unsigned short int)va_arg(l, unsigned int) : va_arg(l, unsigned int));
	int a[20], i = 0, count = 0, len = 0, zeros = 0;
	char *hex = "0123456789ABCDEF";
	unsigned long int temp = n;
	if (n == 0 && prec != 0) len = 1;
	else while (temp > 0) { temp /= 16; len++; }
	if (prec > len) zeros = prec - len;
	if (n == 0 && prec == 0) len = 0;
	while (width-- > (len + zeros)) count += _putchar(' ');
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
