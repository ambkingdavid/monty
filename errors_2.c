#include "monty.h"

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
