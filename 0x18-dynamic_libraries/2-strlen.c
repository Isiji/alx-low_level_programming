#include "main.h"

/**
 * _strlen - returns the length of the string
 * @s: string to be counted
 * Return: gives the length
 */

int _strlen(char *s)
{
int i;
int count = 0;
for (i = 0; s[i] != '\0'; i++)
count++;
return (count);
}
