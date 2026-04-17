#include "main.h"

/**
 * print_rot13 - prints the rot13'ed string and returns count
 * @l: arguments
 * @width: width
 * @precision: precision
 * Return: number of characters printed
 */
int print_rot13(va_list l, int width, int precision)
{
	char *s = va_arg(l, char *);
	int i, j, count = 0, len = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (s == NULL)
		s = "(null)";

	while (s[len])
		len++;

	/* معالجة الدقة (precision) إن وجدت */
	if (precision >= 0 && precision < len)
		len = precision;

	/* معالجة العرض (width) */
	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	/* التحويل والطباعة */
	for (i = 0; s[i] && i < len; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (s[i] == in[j])
			{
				count += _putchar(out[j]);
				break;
			}
		}
		if (!in[j]) /* إذا لم يكن حرفاً أبجدياً (مثل \n أو مسافة) يطبعه كما هو */
			count += _putchar(s[i]);
	}
	return (count);
}
