#include "main.h"

/**
 * get_n_len - calculates number length
 */
int get_n_len(unsigned int n, int base)
{
    int len = 0;
    if (n == 0) return (1);
    while (n > 0) { n /= base; len++; }
    return (len);
}

/**
 * print_base - handles u, o, x, X with padding and minus flag
 */
int print_base(unsigned int n, int base, int hash, int upper, int zero, int minus, int width)
{
    char *set = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    char buffer[50];
    int i = 0, count = 0, len = get_n_len(n, base);

    if (hash && n != 0) len += (base == 8) ? 1 : 2;
    if (!minus && !zero && width > len) while (width > len++) count += _putchar(' ');
    if (hash && n != 0)
    {
        count += _putchar('0');
        if (base == 16) count += _putchar(upper ? 'X' : 'x');
    }
    if (zero && !minus && width > len) while (width > len++) count += _putchar('0');
    if (n == 0) count += _putchar('0');
    else
    {
        while (n > 0) { buffer[i++] = set[n % base]; n /= base; }
        while (--i >= 0) count += _putchar(buffer[i]);
    }
    if (minus && width > len) while (width > len++) count += _putchar(' ');
    return (count);
}

/**
 * print_number - handles d, i with padding and minus flag
 */
int print_number(int n, int plus, int space, int zero, int minus, int width)
{
    unsigned int n1;
    int count = 0, len, sign = 0;
    if (n < 0) { n1 = -n; sign = 1; } else n1 = n;
    len = get_n_len(n1, 10);
    if (sign || plus || space) len++;
    if (!minus && !zero && width > len) while (width > len++) count += _putchar(' ');
    if (sign) count += _putchar('-');
    else if (plus) count += _putchar('+');
    else if (space) count += _putchar(' ');
    if (zero && !minus && width > len) while (width > len++) count += _putchar('0');
    count += print_number_recursion(n1);
    if (minus && width > len) while (width > len++) count += _putchar(' ');
    return (count);
}

int print_number_recursion(unsigned int n1)
{
    int count = 0;
    if (n1 / 10) count += print_number_recursion(n1 / 10);
    return (count + _putchar((n1 % 10) + '0'));
}

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0, plus, space, hash, zero, minus, width;
    if (!format || (format[0] == '%' && !format[1])) return (-1);
    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            plus = space = hash = zero = minus = width = 0; i++;
            while (format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0' || format[i] == '-')
            {
                if (format[i] == '+') plus = 1; else if (format[i] == ' ') space = 1;
                else if (format[i] == '#') hash = 1; else if (format[i] == '0') zero = 1;
                else if (format[i] == '-') minus = 1; i++;
            }
            while (format[i] >= '0' && format[i] <= '9') { width = (width * 10) + (format[i] - '0'); i++; }
            if (format[i] == 'd' || format[i] == 'i') count += print_number(va_arg(args, int), plus, space, zero, minus, width);
            else if (format[i] == 'u') count += print_base(va_arg(args, unsigned int), 10, 0, 0, zero, minus, width);
            else if (format[i] == 'o') count += print_base(va_arg(args, unsigned int), 8, hash, 0, zero, minus, width);
            else if (format[i] == 'x') count += print_base(va_arg(args, unsigned int), 16, hash, 0, zero, minus, width);
            else if (format[i] == 'X') count += print_base(va_arg(args, unsigned int), 16, hash, 1, zero, minus, width);
            else if (format[i] == 'c') count += _putchar(va_arg(args, int));
            else if (format[i] == 's') { char *s = va_arg(args, char *); if (!s) s = "(null)"; while (s && *s) count += _putchar(*s++); }
            else if (format[i] == '%') count += _putchar('%');
            else { count += _putchar('%'); count += _putchar(format[i]); }
        } else count += _putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}
