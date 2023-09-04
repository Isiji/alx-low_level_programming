#include "main.h"

/**
 * read_textfile- Read texts in a file and prints it to STDOUT.
 * @filename: the file being read
 * @letters: length of letters to be read
 * Return: w- actual number of letters it could read and print
 *      0 when function fails or filename is NULL or the file can't be opened.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	char *buff;
	ssize_t count, printed;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);

	buff = (char *)malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(file);
		return (0);
	}

	count = read(file, buff, letters);

	close(file);

	if (count < 0)
	{
		free(buff);
		return (0);
	}
	printed = write(STDOUT_FILENO, buff, count);

	free(buff);

	if (printed < 0 || (ssize_t)printed != count)
		return (0);

	return (count);
}
