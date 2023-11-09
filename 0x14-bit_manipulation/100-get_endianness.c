#include "main.h"

/**
 * get_endianness - gets the endianness
 * Return: zero on success
 */


int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char *bptr = (unsigned char *)&num;

if (*bptr == 1)
{
	return (1);
}
else
{
	return (0);
}
}
