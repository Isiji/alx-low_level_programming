#ifndef DOG_H
#define DOG_H

/**
 * struct dog - defines a new type structure
 * @name: stores name of the dog
 * @age: stores age of the dog
 * @owner: stores name of owner
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
}	dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
#endif
