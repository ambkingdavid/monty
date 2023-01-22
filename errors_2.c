#include "monty.h"
/**
 * swap_error - A function that prints swap error
 * @list: List Argument
 * @line_number: Number Argument
 */
void swap_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}
/**
 * add_error - A function that prints add error in monty
 * @line_number: Number Argument
 */
void add_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - A function that prints add error in monty
 * @line_number: Number Argument
 */
void sub_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}


void div_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}

void mul_error(stack_t **list, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_list(list);
	exit(EXIT_FAILURE);
}
