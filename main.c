#include "monty.h"
#include <stdio.h>
/**
 * main - entry point
 *
 * return : always success
 */
#define BUFFER_SIZE 1024

<<<<<<< HEAD
=======
const bus_t bus = {NULL, NULL, NULL, 0};

>>>>>>> 51de2e9d1d0c63b55951281e8fd53b4f93ca8cc2
int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};
	char *content = NULL;
	FILE *file;
	char buffer[BUFFER_SIZE];
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		content = buffer;
		counter++;
		execute(content, &stack, counter, file);
	}
	free_stack(stack);
	fclose(file);
<<<<<<< HEAD
	return (0);
=======
	return(0);
>>>>>>> 51de2e9d1d0c63b55951281e8fd53b4f93ca8cc2
}
