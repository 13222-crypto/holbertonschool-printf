#include "main.h"

int print_str(va_list l, int width, int precision)
{
	char *s = va_arg(l, char *);
	int i, len = 0, count = 0;

	if (!s) s = "(null)";
	while (s[len]) len++;
	
	/* إذا كان الـ precision أصغر من الطول، نقصر النص */
	if (precision >= 0 && precision < len) len = precision;

	while (width > len) { count += _putchar(' '); width--; }
	for (i = 0; i < len; i++) count += _putchar(s[i]);
	return (count);
}
