#include "main.h"
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	int file_from, file_to, rid, rait;
	int buff[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);

	}
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		close(file_from);
		exit(99);
	}
	while ((rid = read(file_from, buff, BUFSIZE)) > 0)
	{
		rait = write(file_to, buff, rid);
		if (rait == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			close(file_from);
			close(file_to);
			exit(99);
		}
	}
	return (0);
}
