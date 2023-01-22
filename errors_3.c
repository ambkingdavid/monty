#include "monty.h"

/**
 * mod_error - A function that prints mod error error
 * @list: List Argument
 * @line_number: Number Argument
 *
 * Return: EXIT_FAILURE
 */
void mod_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}
/**
 * pchar_error - A function that prints print_character error
 * @list: List Argument
 * @line_number: Number Argument
 *
 * Return: EXIT_FAILURE
 */
void pchar_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}
