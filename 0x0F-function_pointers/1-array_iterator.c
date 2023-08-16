#include <stdio.h>
#include "function_pointers.h"

/**
 * array-iterator - iterates through an array
 * @array: where elements are stored
 * @size_t: measures the size of the array
 * @size: the actual size of the array
 * @action: the function to be executed
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
