#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUFFER_SIZE 1024

/**
 * print_elf_header_info - prints header
 * @header: stores information
 */
void print_elf_header_info(Elf32_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("Class:  %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ?
			"ELF32" : "ELF64");
	printf("Data:    %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little-endian" : "unknown");
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:  %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:    %d\n", header->e_type);
	printf("Entry point address: 0x%x\n", header->e_entry);
}

/**
 * main - use print elf header
 * @argc: argument count
 * @argv: stores arguments
 * Return: 0 on succes
 */

int main(int argc, char *argv[])
{
	const char *elf_filename;
	int fd;
	ssize_t bytes_read;
	Elf32_Ehdr elf_header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	elf_filename = argv[1];
	fd = open(elf_filename, O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", elf_filename);
		exit(98);
	}

	bytes_read = read(fd, &elf_header,
			sizeof(elf_header));

	if (bytes_read != sizeof(elf_header))
	{
		fprintf(stderr, "Error: Cannot read ELF header from file %s\n",
				elf_filename);
		close(fd);
		exit(98);
	}
	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: %s is not an ELF file\n", elf_filename);
		close(fd);
		exit(98);
	}
	print_elf_header_info(&elf_header);

	close(fd);
	return (0);
}

