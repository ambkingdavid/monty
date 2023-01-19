#include "monty.h"


char **op_tokens = NULL;


/**
 * main - a monty scripting language
 * ac: argument counter
 * av: argument array
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
	size_t exit_status;

	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[0]);
		return (EXIT_FAILURE);
	}

	exit_status = execute_monty(fp);

	fclose(fp);
	return (exit_status);
}
