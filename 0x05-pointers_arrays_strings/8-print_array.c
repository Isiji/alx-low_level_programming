#include "main.h"
#include <stdio.h>
/**
 * print_array - prints numbers in an array
 * @a: integers to be printed
 * @n: integer to be printed
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
	printf("%d", a[i]);
	if (i < n - 1)
		printf(", ");
	}
	printf("\n");
}
