#include "main.h"

int get_n_len(unsigned int n, int base)
{
	int len = 0;
	if (n == 0) return (1);
	while (n > 0) { n /= base; len++; }
	return (len);
}

int print_binary(unsigned int n)
{
	int count = 0;
	if (n / 2) count += print_binary(n / 2);
	count += _putchar((n % 2) + '0');
	return (count);
}

int print_rot13(char *s)
{
	int i, j, count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	if (s == NULL) s = "(null)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (s[i] == in[j]) { count += _putchar(out[j]); break; }
		}
		if (!in[j]) count += _putchar(s[i]);
	}
	return (count);
}

int print_base(unsigned int n, int base, int hash, int upper, int zero, int minus, int width, int precision)
{
	char *set = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char buffer[50];
	int i = 0, count = 0, len = get_n_len(n, base), p_len;
	if (precision >= 0) zero = 0;
	p_len = (precision > len) ? precision : len;
	if (hash && n != 0) p_len += (base == 8) ? 1 : 2;
	if (!minus && !zero && width > p_len) while (width > p_len++) count += _putchar(' ');
	if (hash && n != 0) {
		count += _putchar('0');
		if (base == 16) count += _putchar(upper ? 'X' : 'x');
	}
	if (zero && !minus && width > p_len) while (width > p_len++) count += _putchar('0');
	while (precision > len++) count += _putchar('0');
	if (!(precision == 0 && n == 0)) {
		if (n == 0) count += _putchar('0');
		else {
			unsigned int temp = n;
			while (temp > 0) { buffer[i++] = set[temp % base]; temp /= base; }
			while (--i >= 0) count += _putchar(buffer[i]);
		}
	}
	if (minus && width > count) while (width > count) count += _putchar(' ');
	return (count);
}

int print_number(int n, int plus, int space, int zero, int minus, int width, int precision)
{
	unsigned int n1;
	int count = 0, len, p_len, sign = 0;
	if (n < 0) { n1 = -n; sign = 1; } else n1 = n;
	len = get_n_len(n1, 10);
	p_len = (precision > len) ? precision : len;
	if (sign || plus || space) p_len++;
	if (precision >= 0) zero = 0;
	if (!minus && !zero && width > p_len) while (width > p_len++) count += _putchar(' ');
	if (sign) count += _putchar('-');
	else if (plus) count += _putchar('+');
	else if (space) count += _putchar(' ');
	if (zero && !minus && width > p_len) while (width > p_len++) count += _putchar('0');
	while (precision > len++) count += _putchar('0');
	if (!(precision == 0 && n == 0)) count += print_number_recursion(n1);
	if (minus && width > count) while (width > count) count += _putchar(' ');
	return (count);
}

int print_number_recursion(unsigned int n1)
{
	int count = 0;
	if (n1 / 10) count += print_number_recursion(n1 / 10);
	return (count + _putchar((n1 % 10) + '0'));
}

int print_rev(char *s)
{
	int len = 0, count = 0;
	if (!s) s = "(null)";
	while (s[len]) len++;
	for (count = len - 1; count >= 0; count--) _putchar(s[count]);
	return (len);
}

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, plus, space, hash, zero, minus, width, precision;
	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			plus = space = hash = zero = minus = width = 0; precision = -1; i++;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0' || format[i] == '-')
			{
				if (format[i] == '+') plus = 1;
				else if (format[i] == ' ') space = 1;
				else if (format[i] == '#') hash = 1;
				else if (format[i] == '0') zero = 1;
				else if (format[i] == '-') minus = 1;
				i++;
			}
			if (format[i] == '*') { width = va_arg(args, int); i++; }
			else { while (format[i] >= '0' && format[i] <= '9') width = width * 10 + (format[i++] - '0'); }
			if (format[i] == '.') {
				i++;
				if (format[i] == '*') { precision = va_arg(args, int); i++; }
				else { precision = 0; while (format[i] >= '0' && format[i] <= '9') precision = precision * 10 + (format[i++] - '0'); }
			}
			if (format[i] == 'd' || format[i] == 'i') count += print_number(va_arg(args, int), plus, space, zero, minus, width, precision);
			else if (format[i] == 'u') count += print_base(va_arg(args, unsigned int), 10, 0, 0, zero, minus, width, precision);
			else if (format[i] == 'o') count += print_base(va_arg(args, unsigned int), 8, hash, 0, zero, minus, width, precision);
			else if (format[i] == 'x') count += print_base(va_arg(args, unsigned int), 16, hash, 0, zero, minus, width, precision);
			else if (format[i] == 'X') count += print_base(va_arg(args, unsigned int), 16, hash, 1, zero, minus, width, precision);
			else if (format[i] == 'b') count += print_binary(va_arg(args, unsigned int));
			else if (format[i] == 'c') count += _putchar(va_arg(args, int));
			else if (format[i] == 's') {
				char *s = va_arg(args, char *);
				int j = 0; if (!s) s = "(null)";
				while (s[j] && (precision < 0 || j < precision)) count += _putchar(s[j++]);
			}
			else if (format[i] == 'r') count += print_rev(va_arg(args, char *));
			else if (format[i] == 'R') count += print_rot13(va_arg(args, char *));
			else if (format[i] == '%') count += _putchar('%');
			else { count += _putchar('%'); count += _putchar(format[i]); }
		} else count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
