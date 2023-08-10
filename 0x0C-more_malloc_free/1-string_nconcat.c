#include <stdlib.h>
		
#include "main.h"
		

		
/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 * Return: pointer to the resulting string
		
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{

	unsigned int i;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	char *pointer;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		len1++;
	for (i = 0; s2[i] != '\0'; i++)
		len2++;

	pointer = malloc(sizeof(char) * (len1 + n) + 1);
	if (pointer == NULL)
		return (NULL);

	if (n >= len2)
	{
		for (i = 0; s1[i] != '\0'; i++)
			pointer[i] = s1[i];

		for (i = 0; s2[i] != '\0'; i++)
			pointer[len1 + i] = s2[i];

		pointer[len1 + i] = '\0';
	}
	else
	{
		for (i = 0; s1[i] != '\0'; i++)
			pointer[i] = s1[i];

		for (i = 0; i < n; i++)
			pointer[len1 + i] = s2[i];

		pointer[len1 + i] = '\0';
	}
	return (pointer);
}

