#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct parameters - structure for format parameters
 * @precision: precision specifier
 */
typedef struct parameters
{
	unsigned int precision;
	/* يمكنك إضافة fields أخرى هنا مثل flags أو width */
} params_t;

int _printf(const char *format, ...);
int _putchar(char c);

/* نماذج الدوال لمعالجة الأنواع المختلفة */
int print_string(va_list args, params_t *params);
int print_int(va_list args, params_t *params);

#endif
