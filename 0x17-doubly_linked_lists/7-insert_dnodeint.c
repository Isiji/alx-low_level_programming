#include "lists.h"
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	size_t count = 0;

	dlistint_t *newP = malloc(sizeof(dlistint_t));
	dlistint_t *temp = *h;

	if (newP == NULL)
		return NULL;

	newP->prev = NULL;
	newP->n = n;
	newP->next = NULL;

	while (count < idx - 1 && temp != NULL)
	{
		temp = temp->next;
		count++;
	
	}
	newP->next = temp->next;
	newP->prev = temp;
	temp->next->prev = newP;
	temp->next = newP;
	return newP;

}
