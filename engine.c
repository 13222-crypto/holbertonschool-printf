#include "main.h"

int print_str(va_list l, int width, int prec) {
	char *s = va_arg(l, char *);
	int len = 0, count = 0, i;
	if (!s) s = "(null)";
	while (s[len]) len++;
	if (prec >= 0 && prec < len) len = prec;
	while (width-- > len) count += _putchar(' ');
	for (i = 0; i < len; i++) count += _putchar(s[i]);
	return (count);
}

int print_int(va_list l, char mod, int width, int prec) {
	long int n = (mod == 'l') ? va_arg(l, long int) : (mod == 'h' ? (short int)va_arg(l, int) : va_arg(l, int));
	unsigned long int num = (n < 0) ? -n : n;
	unsigned long int temp = num, div = 1;
	int count = 0, len = 0, zeros = 0, neg = (n < 0);
	if (num == 0 && prec != 0) len = 1;
	while (temp > 0) { temp /= 10; len++; }
	if (prec > len) zeros = prec - len;
	if (num == 0 && prec == 0) len = 0;
	while (width-- > (len + zeros + neg)) count += _putchar(' ');
	if (neg) count += _putchar('-');
	while (zeros-- > 0) count += _putchar('0');
	if (len > 0) {
		temp = num; while (temp / div > 9) div *= 10;
		while (div != 0) { count += _putchar('0' + (temp / div)); temp %= div; div /= 10; }
	}
	return (count);
}

int print_binary(va_list l, int width, int precision) {
	unsigned int n = va_arg(l, unsigned int);
	unsigned int m = 2147483648, i, sum = 0;
	unsigned int a[32];
	int count = 0;
	(void)width; (void)precision;
	a[0] = n / m;
	for (i = 1; i < 32; i++) { m /= 2; a[i] = (n / m) % 2; }
	for (i = 0; i < 32; i++) {
		sum += a[i];
		if (sum || i == 31) count += _putchar('0' + a[i]);
	}
	return (count);
}
