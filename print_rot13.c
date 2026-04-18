#include "main.h"
int print_rot13(va_list l, int width, int precision)
{
	char *s = va_arg(l, char *);
	int i, j, count = 0, len = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	(void)width; (void)precision;
	if (s == NULL) s = "(null)";
	while (s[len]) len++;
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
		if (!in[j]) count += _putchar(s[i]);
	}
	return (count);
}
