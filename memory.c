#include "monty.h"

void free_list(stack_t **list)
{
	stack_t *tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
