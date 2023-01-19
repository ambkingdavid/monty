#include "monty.h"

/**
 * swap_error - a script that swap monty error
 * @line_number: number argument
 *
 * Return: EXIT_FAILURE
 */
int swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

int add_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short", line_number);
	return (EXIT_FAILURE);
}
