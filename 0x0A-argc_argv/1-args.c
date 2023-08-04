#include <stdio.h>

/**
 * main - returns the number of arguments passed to it
 * @argc: counts the number of arguments
 * @argv: string of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	(void) argv;

	printf("%d\n", argc - 1);
	return (0);
}
