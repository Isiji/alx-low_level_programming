#include "main.h"

/**
 * _islower - checks if a character is lowercase
 * @c: character to be checked
 * Return: shows 1 if true and 0 if false
 */
int _islower(int c)
{
		if (c >= 'a' && c <= 'z')
			return (1);
		else
			return (0);
	}
