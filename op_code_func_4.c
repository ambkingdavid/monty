#include "monty.h"

void monty_mode(stack_t **stack, unsigned int line_number)
{
	if (strcmp(var.opcode, "queue") == 0)
		var.mode = QUEUE;
	if (strcmp(var.opcode, "stack") == 0)
		var.mode = STACK;
	(void)stack;
	(void)line_number;
}
