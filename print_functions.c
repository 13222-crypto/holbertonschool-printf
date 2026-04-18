#include "main.h"

int print_str(va_list l, int width, int precision)
{
	char *s = va_arg(l, char *);
	int len = 0, count = 0, i;

	if (s == NULL) s = "(null)";
	while (s[len]) len++;

	if (precision >= 0 && precision < len) len = precision;

	while (width > len) { count += _putchar(' '); width--; }
	for (i = 0; i < len; i++) count += _putchar(s[i]);

	return (count);
}
