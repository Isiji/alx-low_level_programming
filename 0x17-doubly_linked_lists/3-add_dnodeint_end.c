#include "lists.h"

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp, *temp2;

	temp2 = malloc(sizeof(dlistint_t));
	
	if (!temp2)
		return NULL;

	temp2->n = n;
	temp2->next = NULL;

	if (!*head)
	{
		temp2->prev = NULL;
		*head = temp2;
		return temp2;
	}
	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;
	
	temp->next = temp2;
	temp2->prev = temp;

	return temp2;
	
	
	
}
