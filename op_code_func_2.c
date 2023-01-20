#include "monty.h"
/**
 * monty_nop - a script containing monty nop function
 * @stack: argument stack
 * @line_number: argument number
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * monty_pop - A script that prints monty pop funtion
 * @stack: stack argument
 * @line_number: number argument
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if ((*stack)->next == NULL)
	{
		pop_error(line_number);
		return;
	}

	node1 = (*stack)->next;
	node2 = node1->next;

	(*stack)->next = node2;
	node2->prev = *stack;

	free(node1);
}
