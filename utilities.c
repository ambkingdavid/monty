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

/**
 * add_node_stack - A function that add node stack
 * @head: Head Counter
 * @n: Integer argurment
 */
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

/**
 * add_node_queue - A function to add node to queue
 * @head: Head counter
 * @n: Integer Argument
 */
void add_node_queue(stack_t **head, int n)
{
	stack_t *tmp, *new;

	new = malloc(sizeof(stack_t));
	tmp = *head;
	if (new == NULL)
		malloc_error(head);
	new->n = n;
	new->next = NULL;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}

	if (tmp == NULL)
	{
		*head  = new;
		new->prev = NULL;
	}
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
}
