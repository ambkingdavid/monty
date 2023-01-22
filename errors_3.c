#include "monty.h"

void mod_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}

void add_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}
