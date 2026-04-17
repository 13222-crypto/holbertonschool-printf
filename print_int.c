#include "main.h"

/**
 * print_int - prints an integer with width and precision
 * @l: va_list
 * @mod: modifier
 * @width: width
 * @prec: precision
 * Return: count of chars printed
 */
int print_int(va_list l, char mod, int width, int prec)
{
	long int n;
	unsigned long int num, temp;
	int count = 0, len = 0, zeros = 0, negative = 0;
	unsigned long int div = 1;

	if (mod == 'l') n = va_arg(l, long int);
	else if (mod == 'h') n = (short int)va_arg(l, int);
	else n = va_arg(l, int);

	if (n < 0) {
		num = -n;
		negative = 1;
	} else num = n;

	temp = num;
	if (num == 0 && prec != 0) len = 1;
	else while (temp > 0) { temp /= 10; len++; }

	if (prec > len) zeros = prec - len;
	
	/* حساب المساحات: الإشارة + الأصفار + الأرقام */
	if (n == 0 && prec == 0) len = 0;
	while (width > (len + zeros + negative)) {
		count += _putchar(' ');
		width--;
	}

	if (negative) count += _putchar('-');
	while (zeros-- > 0) count += _putchar('0');

	if (!(n == 0 && prec == 0)) {
		temp = num;
		while (num / div > 9) div *= 10;
		while (div != 0) {
			count += _putchar('0' + (num / div));
			num %= div;
			div /= 10;
		}
	}
	return (count);
}
