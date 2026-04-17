#include "main.h"

/**
 * print_str - prints string with width support
 * @l: va_list
 * @width: field width
 * Return: number of chars printed
 */
int print_str(va_list l, int width)
{
	char *s = va_arg(l, char *);
	int i, len = 0, count = 0;

	if (!s)
		s = "(null)";

	while (s[len])
		len++;

	/* طباعة المسافات إذا كان العرض المطلوب أكبر من النص */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	for (i = 0; s[i]; i++)
		count += _putchar(s[i]);

	return (count);
}
