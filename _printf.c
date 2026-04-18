#include "main.h"
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, width, prec;
	char mod;
	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++) {
		if (format[i] == '%') {
			i++;
			width = 0; prec = -1; mod = 0;
			while (format[i] == ' ') i++;
			if (format[i] == '*') { width = va_arg(args, int); i++; }
			else while (format[i] >= '0' && format[i] <= '9') width = width * 10 + (format[i++] - '0');
			if (format[i] == '.') {
				i++; prec = 0;
				if (format[i] == '*') { prec = va_arg(args, int); i++; }
				else while (format[i] >= '0' && format[i] <= '9') prec = prec * 10 + (format[i++] - '0');
			}
			if (format[i] == 'l' || format[i] == 'h') mod = format[i++];
			if (format[i] == 'd' || format[i] == 'i') count += print_int(args, mod, width, prec);
			else if (format[i] == 's') count += print_str(args, width, prec);
			else if (format[i] == 'u') count += print_unsigned(args, mod, width, prec);
			else if (format[i] == 'o') count += print_octal(args, mod, width, prec);
			else if (format[i] == 'x') count += print_hex(args, mod, width, prec);
			else if (format[i] == 'X') count += print_HEX(args, mod, width, prec);
			else if (format[i] == 'b') count += print_binary(args, width, prec);
			else if (format[i] == 'R') count += print_rot13(args, width, prec);
			else if (format[i] == 'c') {
				int c = va_arg(args, int);
				while (width-- > 1) count += _putchar(' ');
				count += _putchar(c);
			} else if (format[i] == '%') count += _putchar('%');
			else { count += _putchar('%'); if (mod) count += _putchar(mod); count += _putchar(format[i]); }
		} else count += _putchar(format[i]);
	}
	va_end(args);
	return (count);
}
