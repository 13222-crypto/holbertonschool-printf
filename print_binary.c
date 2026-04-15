#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @args: va_list of arguments
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n;
    unsigned int mask;
    int count;
    int started;

    n = va_arg(args, unsigned int);
    count = 0;
    started = 0;

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }

    mask = 1 << (sizeof(unsigned int) * 8 - 1);

    while (mask > 0)
    {
        if (n & mask)
        {
            _putchar('1');
            count++;
            started = 1;
        }
        else if (started)
        {
            _putchar('0');
            count++;
        }
        mask >>= 1;
    }

    return (count);
}
