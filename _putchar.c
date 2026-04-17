#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to a local buffer
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;
	int written = 0;

	if (c == -1 || i >= 1024)
	{
		written = write(1, buffer, i);
		i = 0;
	}

	if (c != -1)
	{
		buffer[i] = c;
		i++;
		return (1);
	}
	return (written);
}
