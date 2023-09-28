#include <stdio.h>


unsigned int countSetBits(unsigned long int num) 
{
	unsigned int count = 0;
	while (num)
	{
		count += num & 1;
		num >>= 1;
	}
	return count;
}

unsigned int flip_bits(unsigned long int n, unsigned long int m) 
{
	unsigned long int xor_result = n ^ m;

	unsigned int count = countSetBits(xor_result);

	return count;
}
