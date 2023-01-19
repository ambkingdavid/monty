#include "monty.h"

/**
 * unknown_error - a script to handle unknown error
 * opcode: opcode argument
 * line_number: number the line
 *
 * Return: EXIT_FAILURE
 */
int unknown_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}

int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

int push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
