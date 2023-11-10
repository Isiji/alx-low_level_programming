#include "lists.h"
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	size_t count = 0;

	if (head == NULL || *head == NULL)
		return -1;
	temp = *head;

	while (count < index && temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if (temp == NULL)
		return -1;
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	else
		*head = temp->next;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);

	return 1;

}
