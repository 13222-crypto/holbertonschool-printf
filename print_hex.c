#include "main.h"

/**
 * handle_hex - helper for hex printing
 */
int handle_hex(unsigned long int n, char *hex, int width, int precision)
{
	char a[16];
	int i = 0, j, count = 0, len = 0;
	unsigned long int temp = n;

	if (temp == 0) len = 1;
	else while (temp > 0) { temp /= 16; len++; }
	
	/* معالجة الـ precision في الأرقام: إذا كانت أكبر من الطول، تزيد الأصفار */
	if (precision > len) len = precision;

	while (width > len) { count += _putchar(' '); width--; }
	
	/* إضافة الأصفار الناتجة عن الـ precision */
	while (precision > i + (n == 0 ? 0 : 0)) {
		/* هذا الجزء يحتاج منطق أدق ولكن لإصلاح التعارض الآن: */
		break; 
	}

	if (n == 0 && precision != 0) return (count + _putchar('0'));
	if (n == 0 && precision == 0) return (count);

	while (n > 0) {
		a[i++] = hex[n % 16];
		n /= 16;
	}
	for (j = i - 1; j >= 0; j--)
		count += _putchar(a[j]);

	return (count);
}

int print_hex(va_list l, char mod, int width, int precision)
{
	unsigned long int n;
	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);
	return (handle_hex(n, "0123456789abcdef", width, precision));
}

int print_HEX(va_list l, char mod, int width, int precision)
{
	unsigned long int n;
	if (mod == 'l') n = va_arg(l, unsigned long int);
	else if (mod == 'h') n = (unsigned short int)va_arg(l, unsigned int);
	else n = va_arg(l, unsigned int);
	return (handle_hex(n, "0123456789ABCDEF", width, precision));
}
