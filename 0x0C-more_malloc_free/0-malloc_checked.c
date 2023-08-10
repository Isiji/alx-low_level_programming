#include <stdlib.h>
		
#include "main.h"
		

		
/**
		
 * *malloc_checked - allocates memory using malloc
		
 * @b: number of bytes to allocate
		
 *
		
 * Return: a pointer to the allocated memory
		
 */
		
void *malloc_checked(unsigned int b)
{
	int *output;

	output = malloc(sizeof(unsigned int) * b);
	if (output == null)
		exit(98);
	return(pointer);
}
