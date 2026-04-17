#include "main.h"

/**
 * _printf - custom printf with width support
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, width;
	char mod;

	if (!format || (format[0] == '%' && !format[1])) return (-1);
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			width = 0;
			/* استخراج الـ Width من النص */
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = (width * 10) + (format[i] - '0');
				i++;
			}
			/* استخراج الـ Modifier */
			mod = 0;
			if (format[i] == 'l' || format[i] == 'h')
			{
				mod = format[i];
				i++;
			}
			/* معالجة الحالات */
			if (format[i] == 'd' || format[i] == 'i') count += print_int(args, mod, width);
			else if (format[i] == 's') count += print_str(args, width);
			else if (format[i] == 'c')
			{
				while (width > 1) { count += _putchar(' '); width--; }
				count += _putchar(va_arg(args, int));
			}
			else if (format[i] == '%') count += _putchar('%');
			else
			{
				count += _putchar('%');
				if (width) /* إعادة طباعة الأرقام كأنها نص عادي إذا لم نجد حرف تحويل */
				{
					/* كود إضافي هنا للتعامل مع الحالات غير المعروفة */
				}
				count += _putchar(format[i]);
			}
		}
		else count += _putchar(format[i]);
		i++;
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
