#include "monty.h"

global_t glo;

/**
 * free_glo - frees the global variables
 *
 * Return: no return
 */
void free_glo(void)
{
	free_dlistint(glo.head);
	free(glo.buffer);
	fclose(glo.fdt);
}

/**
 * start_glo - initializes the global variables
 *
 * @fdt: file descriptor
 * Return: no return
 */
void start_glo(FILE *fdt)
{
	glo.lifo = 1;
	glo.cont = 1;
	glo.arg = NULL;
	glo.head = NULL;
	glo.fdt = fdt;
	glo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fdt;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fdt = fopen(argv[1], "r");

	if (fdt == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fdt);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fdt;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fdt = check_input(argc, argv);
	start_glo(fdt);
	nlines = getline(&glo.buffer, &size, fdt);
	while (nlines != -1)
	{
		lines[0] = _strtoky(glo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glo();
				exit(EXIT_FAILURE);
			}
			glo.arg = _strtoky(NULL, " \t\n");
			f(&glo.head, glo.cont);
		}
		nlines = getline(&glo.buffer, &size, fdt);
		glo.cont++;
	}

	free_glo();

	return (0);
}

