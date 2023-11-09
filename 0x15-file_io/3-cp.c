#include "main.h"
#include <errno.h>

#define BUFSIZE 1024
/**
 * main - copies files
 * @argc: argument count
 * @argv: stores the arguments
 * Return: returns 0 if successfull
 */

int main(int argc, char *argv[])
{
	const char *file_from, *file_to;
	int fd_from, fd_to;
	ssize_t rid, rait;
	char buff[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	file_from = argv[1];
	file_to = argv[2];
	fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);

	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
		close(fd_from);
		exit(99);
	}
	while ((rid = read(fd_from, buff, BUFSIZE)) > 0)
	{
		rait = write(fd_to, buff, rid);
		if (rait == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}
	if (rid == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(100);
	}
	return (0);
}
