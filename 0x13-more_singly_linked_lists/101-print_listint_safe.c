#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *snail, *gaz;
	size_t nod = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	snail = head->next;
	gaz = (head->next)->next;

	while (gaz)
	{
		if (snail == gaz)
		{
			snail = head;
			while (snail != gaz)
			{
				nod++;
				snail = snail->next;
				gaz = gaz->next;
			}

			snail = snail->next;
			while (snail != hare)
			{
				nodes++;
				snail = snail->next;
			}

			return (nod);
		}

		snail = snail->next;
		gaz = (gaz->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nod, index = 0;

	nod = looped_listint_len(head);

	if (nod == 0)
	{
		for (; head != NULL; nod++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nod);
}

