#include "monty.h"


void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	temp = (*stack)->next;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		malloc_error();
		return;
	}
	if (op_tokens[1] == NULL ||
			(atoi(op_tokens[1]) == 0 && op_tokens[1][0] != '0'))
	{
		push_error(line_number);
		return;
	}

	new->n = atoi(op_tokens[1]);
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
		return;
	}

	node1 = (*stack)->next;
	node2 = node1->next;
	node2->n += node1->n;
	(*stack)->next = node2;
	free(node1);
	(void) line_number;
}

void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node1;

	if ((*stack)->next == NULL)
	{
		pint_error(line_number);
		return;
	}

	node1 = (*stack)->next;
	printf("%d\n", node1->n);
	(void) line_number;
}

void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2, *node3;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		swap_error(line_number);
		return;
	}
	else
	{
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
}
