#include "monty.h"


void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	temp = (*stack)->next;
	new = malloc(sizeof(stack_t));
// handle malloc error
	if (new == NULL)
		malloc_error();
//handle no argument error
	if (var.arg == NULL)
		push_error(line_number);
// handle not integer arg error
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
