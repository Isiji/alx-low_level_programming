#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count = 0;
	listint_t *node;
	listint_t *temp;

	if (*head != NULL)
		return (NULL);
	node = malloc(sizeof(listint_t));

	if (!node)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (idx == 0)
	{
		node->next = *head;
		*head = node;

		return (node);
	}
	temp = *head;

	while (temp && count < (idx - 1))
	{
		temp = temp->next;
		count++;
	}
	if (!temp)
	{
		free(node);
		return (NULL);
	}

	node->next = temp->next;
	temp->next = node;
	return (node);
}
