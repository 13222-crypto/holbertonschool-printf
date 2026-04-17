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

	/* إذا أرسلنا -1 أو امتلأ البفر، نطبع كل اللي فيه */
	if (c == -1 || i >= 1024)
	{
		write(1, buffer, i);
		i = 0;
	}

	/* إذا كان حرفاً عادياً، نخزنه في البفر */
	if (c != -1)
	{
		buffer[i] = c;
		i++;
	}

	return (1);
}
