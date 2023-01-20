#include "monty.h"
/**
 * execute_monty - it execute a monty file
 * @fp: monty file
 *
 * Return: exit_status
 */
int execute_monty(FILE *fp)
{
	char *line;
	stack_t *stack;
	size_t n, exit_status;
	unsigned int line_number, optoken_len;
	void (*opcode_func)(stack_t**, unsigned int);

	exit_status = EXIT_SUCCESS;

	if (init_list(&stack) == EXIT_FAILURE)
	{
		exit_status = malloc_error();
	}

	line_number = 0;
	while (getline(&line, &n, fp) != -1)
	{
		line_number++;
		op_tokens = get_tokens(line);
		if (op_tokens == NULL)
			exit_status = malloc_error();

		opcode_func = get_op(op_tokens[0]);
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, op_tokens[0]);
			/* free memory */
			return (EXIT_FAILURE);
		}
/*		optoken_len = get_op_token_len();*/
		opcode_func(&stack, line_number);

	}
	/* free memory */
	return (exit_status);
}
/**
 * get_tokens - a script that prints monty token
 * @linestr: Line String argument
 *
 * Return: tokens
 */
char **get_tokens(char *linestr)
{
	char **tokens, *token;
	int i;

	tokens = malloc(sizeof(char *) * strlen(linestr));
	if (tokens == NULL)
		return (NULL);

	token = strtok(linestr, " \n\t\b\a");
	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t\b\a");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * init_list - a script that initialize init list
 * @stack: argument stack
 *
 * Return: exit_success
 */
int init_list(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (!s)
		return (EXIT_FAILURE);

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - a script that checks mode
 * @stack: argument stack
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
 * get_op - a script that prints opcode
 * @opcode: opcode argument
 *
 * Return: NULL
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
