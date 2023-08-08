#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **output;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	output = malloc(sizeof(int *) * height);

	if (output == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
	{
		output[x] = malloc(sizeof(int) * width);

		if (output[x] == NULL)
		{
			for (; x >= 0; x--)
				free(output[x]);

			free(output);
			return (NULL);
		}
	}

	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			output[x][y] = 0;
	}

	return (output);
}
