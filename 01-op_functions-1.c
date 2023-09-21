#include "monty.h"

/**
 * op_push - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int number = 0;

	(void)stack;
	(void)line_number;

	number = atoi(glob.arg);

	add_dnodeint_end(stack, number);
}

/**
 * op_pop - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * op_pall - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top = traverse_end(*stack);

	(void)line_number;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
}

/**
 * op_pint - Pushes an item on the stack
 * @stack: The Stack
 * @line_number: Line where command is
 * Return: Always Void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	if (glob.TOS1 == -99)
	{
		fprintf(stderr, "Stack is empty!\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", glob.TOS1);
}
