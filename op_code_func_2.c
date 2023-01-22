#include "monty.h"

/**
 * monty_nop - A function for monty nop
 * @stack: Stack Argument
 * @line_number: Number Argument
 */

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * monty_pop - A function that inserts stack in monty
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

	if (node2 == NULL)
	{
		*stack = NULL;
		free(node1);
	}
	else
	{
		(*stack) = node2;
		node2->prev = NULL;
		free(node1);
	}

}

/**
 * monty_sub- A function that prints monty add
 * @stack: Stack Argument
 * @line_number: Number Argument
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		sub_error(stack, line_number);
	}

	node1 = (*stack);
	node2 = node1->next;
	node2->n -= node1->n;
	(*stack) = node2;
	free(node1);
}
/**
 * monty_div - A function monty division
 * @stack: Stack Argument
 * @line_number: Number Argument
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	node1 = (*stack);
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		div_error(stack, line_number);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	node2 = node1->next;
	node2->n /= node1->n;
	(*stack) = node2;
	free(node1);
}
/**
 * monty_mul - A function for stack monty multiplication
 * @stack: Stack Argument
 * @line_number: Number Argument
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		mul_error(stack, line_number);
	}

	node1 = (*stack);
	node2 = node1->next;
	node2->n *= node1->n;
	(*stack) = node2;
	free(node1);
}
