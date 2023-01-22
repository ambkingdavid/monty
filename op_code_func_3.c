#include "monty.h"

void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	node1 = (*stack);
	if (node1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		mod_error(stack, line_number);
	}

	node2 = node1->next;
	node2->n %= node1->n;
	(*stack) = node2;
	free(node1);
}



void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node1;

	if ((*stack) == NULL)
	{
		pchar_error(stack, line_number);
	}
	node1 = (*stack);
	if (node1->n > 127 || node1->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", node1->n);
}
