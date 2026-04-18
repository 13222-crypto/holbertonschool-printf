#include "main.h"

/**
 * print_string - prints a string with precision
 * @args: arguments
 * @params: parameters
 * Return: number of chars printed
 */
int print_string(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	int i = 0, count = 0;

	if (!str)
		str = "(null)";

	/* إذا كانت هناك دقة محددة، نطبع حروفاً بقدر الدقة فقط */
	while (str[i])
	{
		if (params->precision != 0 && i >= (int)params->precision)
			break;
		_putchar(str[i]);
		count++;
		i++;
	}
	return (count);
}
