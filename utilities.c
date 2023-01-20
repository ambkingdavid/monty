#include "monty.h"

/**
 * check_arg - a script that checks monty argument
 * @arg: argument checker
 *
 * Return: 1
 */
int check_arg(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (arg[i] < '0' || arg[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
