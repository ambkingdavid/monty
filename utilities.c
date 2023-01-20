#include "monty.h"

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
