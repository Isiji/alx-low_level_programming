#include "main.h"

/**
 * countSetBits - counts the set of bits
 * Return: returns count
 * @num: the number of bits
 */
unsigned int countSetBits(unsigned long int num)
{
	unsigned int count = 0;

	while (num)
	{
		count += num & 1;
		num >>= 1;
	}
	return (count);
}

#include "main.h"
/**
 * flip_bits - flips the bits counted
 * @n: used to count
 * @m: used to change when flipping
 * Return: count
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;

	unsigned int count = countSetBits(xor_result);

	return (count);
}
