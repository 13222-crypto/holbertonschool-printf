#include "main.h"

/**
 * get_precision - Extracts the precision from the format string
 * @p: The format string
 * @params: parameters struct
 * @args: arguments list
 * Return: pointer to the next character after precision
 */
char *get_precision(char *p, params_t *params, va_list args)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(args, int);
		p++;
	}
	else
	{
		while (*p >= '0' && *p <= '9')
		{
			d = d * 10 + (*p - '0');
			p++;
		}
	}
	params->precision = d;
	return (p);
}
