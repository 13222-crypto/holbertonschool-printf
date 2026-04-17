#include "main.h"

/**
 * print_rot13 - prints the rot13'ed string
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

	if (precision >= 0 && precision < len)
		len = precision;

	while (width > len)
	{
		count += _putchar(' ');
		width--;
	}

	for (i = 0; i < len; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (s[i] == in[j])
			{
				count += _putchar(out[j]);
				break;
			}
		}
		if (!in[j])
			count += _putchar(s[i]);
	}
	return (count);
}
