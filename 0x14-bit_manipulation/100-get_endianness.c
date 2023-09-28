#include "main.h"


int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char* bptr = (unsigned char*)&num;

if (*bptr == 1)
{
	return (1);
}
else
{
	return (0);
}
}
