#include "main.h"

/**
 * print_int - prints integer with precision
 * @l: va_list
 * @mod: modifier
 * @width: width
 * @prec: precision
 * Return: count
 */
int print_int(va_list l, char mod, int width, int prec)
{
	long int n;
	unsigned long int num, temp;
	int count = 0, len = 0, zeros = 0, neg = 0;
	unsigned long int div = 1;

	if (mod == 'l') n = va_arg(l, long int);
	else if (mod == 'h') n = (short int)va_arg(l, int);
	else n = va_arg(l, int);

	if (n < 0) { num = -n; neg = 1; }
	else num = n;

	/* حساب طول الرقم الفعلي */
	temp = num;
	if (num == 0 && prec != 0) len = 1;
	else {
		while (temp > 0) { temp /= 10; len++; }
	}

	/* إذا كانت الدقة أكبر من الطول، نحتاج أصفار */
	if (prec > len) zeros = prec - len;
	
	/* حالة خاصة: الدقة 0 والرقم 0 لا يطبع شيء */
	if (num == 0 && prec == 0) len = 0;

	/* طباعة المسافات (width) */
	while (width > (len + zeros + neg)) {
		count += _putchar(' ');
		width--;
	}

	if (neg) count += _putchar('-');
	
	/* طباعة أصفار الدقة (precision) */
	while (zeros-- > 0) count += _putchar('0');

	/* طباعة الرقم نفسه */
	if (len > 0) {
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
