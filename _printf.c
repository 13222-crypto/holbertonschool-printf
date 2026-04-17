#include "main.h"

/**
 * _printf - custom printf with length modifiers
 * @format: string
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char mod;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			mod = 0;
			if (format[i] == 'l' || format[i] == 'h')
			{
				mod = format[i];
				i++;
			}
			if (format[i] == '\0')
			{
				count += _putchar('%');
				break;
			}
			/* الشغل كله هنا: إذا لقينا حرف تحويل معروف نعالجه */
			if (format[i] == 'd' || format[i] == 'i') count += print_int(args, mod);
			else if (format[i] == 'u') count += print_unsigned(args, mod);
			else if (format[i] == 'o') count += print_octal(args, mod);
			else if (format[i] == 'x') count += print_hex(args, mod);
			else if (format[i] == 'X') count += print_HEX(args, mod);
			else if (format[i] == 's') count += print_str(args);
			else if (format[i] == 'c') count += _putchar(va_arg(args, int));
			else if (format[i] == 'b') count += print_binary(args);
			else if (format[i] == '%') count += _putchar('%');
			else
			{
				/* إذا ما عرفنا الحرف، نطبع الـ % ونرجع نعتبر الـ mod حرف عادي */
				count += _putchar('%');
				if (mod)
					i--; /* نرجع خطوة وراء عشان نطبع الـ l أو الـ h كحرف عادي */
				else
					count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
