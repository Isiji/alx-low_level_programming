#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *present, *delnode;
	unsigned int count;

	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (count = 0; count > 0 && count < (index - 1); count++)
	{
		present = present->next;
	}
	if (!present || !present->next)
		return (-1);

	delnode = present->next;

	present->next = delnode->next;
	free(delnode);
	return (1);
}
