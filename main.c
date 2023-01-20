#include "monty.h"


variables var = {NULL, NULL};

/**
 * main - a monty scripting language
 * @ac: argument counter
 * @av: argument array
 *
 * Return: exit_status
 */
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	FILE *fp;

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
