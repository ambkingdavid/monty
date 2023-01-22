#include "monty.h"

/**
 * check_arg - a script that checks monty argument
 * @arg: argument checker
 *
 * Return: 1
 */
int check_arg(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (arg[i] < '0' || arg[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

void add_node_stack(stack_t **head, int n)
{
	stack_t *tmp, *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_error(head);

	if (*head)
	{
		tmp = *head;
		new->n = n;
		new->next = tmp;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		new->n = n;
		new->prev = NULL;
		new->next = NULL;
		*head = new;
	}
}

void add_node_queue(stack_t **head, int n)
{
	stack_t *tmp, *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		malloc_error(head);

	if (*head == NULL || head == NULL)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		new->next = NULL;
		new->prev = tmp;
		tmp->next = new;
	}
}
