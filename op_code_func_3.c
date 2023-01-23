#include "monty.h"
/**
 * monty_mod - A function that prints monty  mod
 * @stack: List Argument
 * @line_number: Number Argument
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node1, *node2;

	node1 = (*stack);
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		mod_error(stack, line_number);
	}
	if (node1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	node2 = node1->next;
	node2->n %= node1->n;
	(*stack) = node2;
	free(node1);
}

/**
 * monty_pchar - A function that prints character in monty
 * @stack: List Argument
 * @line_number: Number Argument
 *
 * Return: EXIT_FAILURE
 */
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
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", node1->n);
}
/**
 * monty_pstr - A function for monty pstr
 * @stack: List Argument
 * @line_number: Number Argument
 *
 * Return: EXIT_FAILURE
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_number;
}

/**
 * monty_rotl - A function for stack rotl
 * @stack: List Argument
 * @line_number: Number Argument
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = (*stack)->next;
	top->prev = NULL;

	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = top;
	(void)line_number;
}

/**
 * monty_rotr - A function for stack rotation_right
 * @stack: List Argument
 * @line_number: Number Argument
 *
 */

void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top, *bottom;
	int count;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = (*stack);

	temp = *stack;
	count = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}

	temp->prev = NULL;
	temp->next = top;
	(*stack) = temp;

	bottom = temp;
	while (count > 0)
	{
		bottom = bottom->next;
		count--;
	}
	bottom->next = NULL;

	(void)line_number;
}
