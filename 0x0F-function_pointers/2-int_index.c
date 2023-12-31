#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - returns the index of the first element
 * @array: where the elements are stored
 * @size: size of the array
 * @cmp: a function that compares the elemnents
 * Return: negative one
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);
	if (size <= 0)
		return (-1);
	for (i = 0; i <= size; i++)
		if (cmp(array[i]) == 1)
			return (i);
	return (-1);
}
