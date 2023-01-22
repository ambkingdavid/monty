#include "monty.h"

/**
 * monty_nop - A script for nop
 * @stack: Stack Argument
 * @line_number: Number Argument
 */

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * monty_pop - A script that inserts stack in monty function
 * @stack: Stack Argument
 * @line_number: Number Argument
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if ((*stack) == NULL)
	{
		pop_error(stack, line_number);
	}

	node1 = (*stack);
	node2 = node1->next;

	(*stack) = node2;
	node2->prev = NULL;

	free(node1);
}
