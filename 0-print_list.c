#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */
size_t print_list(const list_t *h)
{
	int count = 0;

	while (h)
	{
	if (h == NULL)
		printf("[0] (nil)");

	else
	{
		printf("[%u] %s", h->len, h->str);
		h = h->next;
		count++;
	}
	}
	return (count);

}
