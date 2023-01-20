#include "monty.h"
/**
 * unknown_error - A function that prints unknown error
 * @opcode: Opcode Argument
 * @line_number: Number Argument
 */
void unknown_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * malloc_error - A function that prints malloc error
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 * push_error - A function that prints push error
 * @line_number: Number Argument
 */
void push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * pint_error - A function that prints pint error
 * @line_number: Number Argument
 */
void pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * pop_error - A function that prints pop error
 * @line_number: Number Argument
 */
void pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
