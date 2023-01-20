#include "monty.h"


variables var = {NULL, NULL};

/**
 * main - A monty scripting language
 * @ac: Argument counter
 * @av: Argument array
 *
 * Return: exit_status
 */
int main(int ac, char *av[])
{
	FILE *fp;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[0]);
		return (EXIT_FAILURE);
	}

	execute_monty(fp);

	fclose(fp);
	return (0);
}
