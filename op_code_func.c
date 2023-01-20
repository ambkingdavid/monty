#include "monty.h"


/**
 * monty_push - A script that pushes monty function
 * @stack: Stack Argument
 * @line_number: Number Argument
 */

void monty_push(stack_t **stack, unsigned int line_number)

{
	stack_t *new, *temp;

	temp = (*stack)->next;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_error();
	if (var.arg == NULL)
		push_error(line_number);
	if (check_arg(var.arg) != 1)
		push_error(line_number);
	new->n = atoi(var.arg);
	if (check_mode(stack) == STACK)
	{
		new->next = temp;
		new->prev = *stack;
		(*stack)->next = new;
	}
	if (check_mode(stack) == QUEUE)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->next = NULL;

		new->prev = temp;
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

	temp = (*stack)->next;

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

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		add_error(line_number);
	}

	node1 = (*stack)->next;
	node2 = node1->next;
	node2->n += node1->n;
	(*stack)->next = node2;
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

	if ((*stack)->next == NULL)
	{
		pint_error(line_number);
	}

	node1 = (*stack)->next;
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

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		swap_error(line_number);
	}
	node1 = (*stack)->next;
	node2 = node1->next;
	node3 = node2->next;

	(*stack)->next = node2;
	node2->next = node1;
	node1->next = node3;
	node2->prev = *stack;
	node1->prev = node2;
	node3->prev = node1;
}
