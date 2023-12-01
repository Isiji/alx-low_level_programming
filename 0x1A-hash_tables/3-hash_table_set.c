#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: pointer to hash table
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *vcpy, *kcpy;
	hash_node_t  *list, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);

	vcpy = strdup(value);
	if (!vcpy)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	list = ht->array[index];

	while (list)
	{
		if (!strcmp(key, list->key))
		{
			free(list->value);
			list->value = vcpy;
			return (1);
		}
		list = list->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(vcpy);
		return (0);
	}
	kcpy = strdup(key);
	if (!kcpy)
		return (0);
	new_node->key = kcpy;
	new_node->value = vcpy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

