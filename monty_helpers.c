#include "monty.h"
/**
 * execute_monty - it execute a monty file and function
 * @fp: monty file
 *
 */
void execute_monty(FILE *fp)
{
	char *line = NULL;
	stack_t *list = NULL;
	size_t n = 0;
	ssize_t read;
	unsigned int line_number;
	void (*opcode_func)(stack_t**, unsigned int);

	line_number = 0;
	while ((read = getline(&line, &n, fp)) != -1)
	{
		line_number++;
		if (read == 1)
			continue;
		get_tokens(line);
		if (var.opcode == NULL)
			continue;
		if (var.opcode[0] == '#')
			continue;
		opcode_func = get_op(var.opcode);
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, var.opcode);

			free_list(&list);
			exit(EXIT_FAILURE);
		}
		opcode_func(&list, line_number);
	}
	free(line);
	free_list(&list);
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
	(void)stack;
	if (var.mode == STACK)
		return (STACK);
	else if (var.mode == QUEUE)
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
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"queue", monty_mode},
		{"stack", monty_mode},
		{NULL, NULL}
	};

	for (i = 0; operations[i].opcode; i++)
	{
		if (strcmp(opcode, operations[i].opcode) == 0)
			return (operations[i].f);
	}
	return (NULL);
}
