#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define STACK 1
#define QUEUE 0

extern char **op_tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int execute_monty(FILE *fp);
int init_list(stack_t **stack);
int check_mode(stack_t **stack);
void (*get_op(char *opcode))(stack_t**, unsigned int);
char **get_tokens(char *linestr);

/*op_code_functions */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);

/* errors */

int unknown_error(char *opcode, unsigned int line_number);
int malloc_error(void);
int push_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int swap_error(unsigned int line_number);
int add_error(unsigned int line_number);


/* utilities */
unsigned int get_op_token_len(void);

#endif /* MONTY_H */
