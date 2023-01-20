#include "monty.h"
#include <stdio.h>
/**
 * execute_monty - it execute a monty file and function
 * @fp: monty file
 *
 */
void execute_monty(FILE *fp)
{
	char *line = NULL;
	stack_t *stack;
	size_t n = 0;
	ssize_t read;
	unsigned int line_number;
	void (*opcode_func)(stack_t**, unsigned int);

	init_list(&stack);
	if (stack == NULL)
		malloc_error();

	line_number = 0;
	while ((read = getline(&line, &n, fp)) != -1)
	{
		line_number++;
		get_tokens(line);
		opcode_func = get_op(var.opcode);
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, var.opcode);
			/* free memory */
			exit(EXIT_FAILURE);
		}
		opcode_func(&stack, line_number);
	}
	/* free memory */
	free(var.opcode);
	free(var.arg);
}
/**
 * get_tokens - A function that gets monty tokens from monty files
 * @linestr: String Argument
 */
void get_tokens(char *linestr)
{
	char *token;

	token = strtok(linestr, " \n\t\b\a");
	var.opcode = token;
	token = strtok(NULL, " \n\t\b\a");
	var.arg = token;
}
/**
 * init_list - A function that gets token in monty file
 * @stack: Stack Argument
 */
void init_list(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;
}
/**
 * check_mode - A function that checks monty monty
 * @stack: Stack Argument
 *
 * Return: 2
 */
int check_mode(stack_t **stack)
{
	if ((*stack)->n == STACK)
		return (STACK);
	else if ((*stack)->n == QUEUE)
		return (QUEUE);
	return (2);
}
/**
 * get_op - A function that gets monty op code from monty file
 * @opcode: opcode Argument
 *
 * Return: Null
 */
void (*get_op(char *opcode))(stack_t**, unsigned int)
{
	int i;

	instruction_t operations[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"add", monty_add},
		{"pint", monty_pint},
		{"swap", monty_swap},
		{"pop", monty_pop},
		{"nop", monty_nop},
		{NULL, NULL}
	};

	for (i = 0; operations[i].opcode; i++)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
			return (operations[i].f);
	}
	return (NULL);
}
