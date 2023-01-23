#include "monty.h"


/**
 * monty_push - A script that pushes monty function
 * @stack: Stack Argument
 * @line_number: Number Argument
 */

void monty_push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.arg == NULL)
		push_error(stack, line_number);

	if (check_arg(var.arg) != 1)
		push_error(stack, line_number);

	n = atoi(var.arg);
	if (var.mode == STACK)
	{
		add_node_stack(stack, n);
	}
	else if (var.mode == QUEUE)
	{
		add_node_queue(stack, n);
	}
}

/**
 * monty_pall - A script that prints all monty functions
 * @stack: Stack Argument
 * @line_number: Number Argument
 */

void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}

/**
 * monty_add - A script that prints monty add
 * @stack: Stack Argument
 * @line_number: Number Argument
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		add_error(stack, line_number);
	}

	node1 = (*stack);
	node2 = node1->next;
	node2->n += node1->n;
	(*stack) = node2;
	free(node1);
}

/**
 * monty_pint - A script that prints all monty functions
 * @stack: Stack Argument
 * @line_number: Number Argument
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node1;

	if ((*stack) == NULL)
	{
		pint_error(stack, line_number);
	}

	node1 = (*stack);
	printf("%d\n", node1->n);
}

/**
 * monty_swap - A script that prints monty swap
 * @stack: Stack Argument
 * @line_number: Number Argument
 */

void monty_swap(stack_t **stack, unsigned int line_number)

{
	stack_t *node1, *node2, *node3;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		swap_error(stack, line_number);
	}
	node1 = (*stack);
	node2 = node1->next;
	node3 = node2->next;

	node2->prev = NULL;
	node2->next = node1;
	node1->prev = node2;
	node1->next = node3;
	(*stack) = node2;
}
