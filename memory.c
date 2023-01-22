#include "monty.h"

/**
 * free_list - Function for free list
 * @list: List Argument
 */
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
