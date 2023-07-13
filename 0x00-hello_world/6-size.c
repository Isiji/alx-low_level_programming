#include <stdio.h>
/**
 * main - start of program
 *
 * Return: 0 (success)
 */
int main(void)
{
	printf("Size of a char:%lu byte(s)", sizeof(char));
	printf("Size of int:%lu byte(s)", sizeof(int));
	printf("Size of long int:%lu bytes(s)", sizeof(long int));	
	printf("Size of long long int: %lu byte(s)", sizeof(long long int));
	printf("Size of float: %lu byte(s)", sizeof(float));
	return (0);
}
