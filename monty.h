#ifndef MONTY_H
#define MONTY_H

/*include header files*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define _POSIX_C_SOURCE 200809L
#define __GNU_SOURCE

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

/*ARRAY OF ALL THE LINES */

void free_arr(char **array);
void print_testign(char **array);

void op_push(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

extern char *item;

/*Utilities - Convert alphabet to integer*/
int _atoi(char *s);
stack_t *traverse_end(stack_t *stack);
stack_t *add_dnodeint_end(stack_t **head, const int n);
char *_strdup(char *str);

#endif /*MONTY_H*/
