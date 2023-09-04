#include "main.h"

/**
 * append_text_to_file - Appends a string of text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 * Return: If the function fails or filename is NULL - -1.
 *     If the file does not exist the user lacks write permissions - -1.
 *     Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_APPEND);

	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		ssize_t written = write(file, text_content, strlen(text_content));

		if (written == -1)
		{
			close(file);

		return (-1);
		}
	}
	return (file);
}
