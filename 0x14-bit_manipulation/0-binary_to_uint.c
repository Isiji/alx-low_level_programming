#include "main.h"
#include <string.h>
/**
 * binary_to_uint - converts a binary number to unsigned int
 * @string: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *string)
{
	unsigned int num = 0;

	if (!string)
		return (0);

	while (*string)
	{
		if (*string == '0' || *string == '1')
		{
			num <<= 1;
			num |= (*string - '0');
		}
		else
		{
			return (0);
		}
		string++;

	}
	return (num);
}
