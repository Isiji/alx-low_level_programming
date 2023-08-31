#include "main.h"
#include <string.h>
/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int len, i;

	if(!b)
		return (0);

	len = strlen(b);

	for (i = 0; i < len; i++)
	{
		if (*b == '0')
			num <<= 1;

		else if (*b == '1')
		{
			num <<= 1;
			num |= 1;
		}
		else
			return (0);

	}
	return (num);
}
