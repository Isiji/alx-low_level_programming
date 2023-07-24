#include "main.h"

/**
 * swap_int - swaps values of integers
 * @a: integer one
 * @b: integer two
 * Return: always zero
 */
void swap_int(int *a, int *b)
{
int c;
c = *a;
*a = *b;
*b = c;
}
