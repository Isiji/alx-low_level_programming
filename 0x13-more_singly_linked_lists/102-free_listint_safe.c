#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current;
	listint_t *holder;

	if (!h || !*h)
		return (0);

	current = *h;

	while (current)
	{
		len++;

		if (current > current->next)
		{
			holder = current->next;
			free(current);
			current = holder;
		}
		else
		{
			free(current);
			*h = NULL;
			break;
		}
	}

	return (len);
}
