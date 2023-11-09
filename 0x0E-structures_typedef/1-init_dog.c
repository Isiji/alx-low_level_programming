#include <stdio.h>
#include "dog.h"

/**
 * init_dog - initialises the struct dog
 * @d: pointer for the dog_struct
 * @name: a pointer to the names stored
 * @age: pointer that stores age
 * @owner: pointer that stores name of the owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{	d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
