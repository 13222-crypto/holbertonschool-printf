#include "main.h"

/**
 * _printf - custom printf function with buffer
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			/* هنا نضع حالات المعالجة (u, o, x, c, s...) */
			/* كل الدوال المساعدة ستنادي _putchar */
			if (format[i] == '%')
				count += _putchar('%');
			/* ... بقية الحالات ... */
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	/* إفراغ البفر النهائي قبل الخروج */
	_putchar(-1); 
	va_end(args);
	return (count);
}
