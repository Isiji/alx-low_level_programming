#include "main.h"

/**
 * puts2 - prints characters of a string
 * @str: where the string is stored
 * Return: void
 */

void puts2(char *str)
{
int i;
for (i = 0; str[i] != '\0'; i++)
{
	if (i % 2 == 0)
		_putchar(str[i]);
}
	_putchar('\n');
}
