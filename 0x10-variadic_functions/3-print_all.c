#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int i, count;
	char *str;

	va_list file;

	va_start(file, format);

	i = 0;

	while (format != NULL && format[i] != '\n')
	{
		switch (format[i])
		{
			case 'i':
				printf("%d", va_arg(file, int));
				count = 0;
				break;
			case 'f':
				printf("%f", va_arg(file, double));
				count = 0;
				break;
			case 'c':
				printf("%c", va_arg(file, int));
				count = 0;
				break;
			case 's':
				str = va_arg(file, char*);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				count = 1;
				break;
		}
		if (format[i + 1] != '\0' && count == 0)
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(file);


}
