#include "monty.h"

/**
 * get_op_token_len - a script that print token lenght
 *
 * Return: len
 */
unsigned int get_op_token_len(void)
{
	unsigned int len;

	len = 0;
	while (*op_tokens[len])
	{
		len++;
	}
	return (len);
}
