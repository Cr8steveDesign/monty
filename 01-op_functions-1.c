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
	stack_t *new_node = NULL;

	(void)stack;
	(void)line_number;
	new_node = malloc(sizeof(stack_t));

	number = atoi(item);
	new_node->n = number;
	new_node->next = NULL;

	if (stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}

	add_dnodeint_end(stack, number);

	printf("The Push command was found at line %d\n", line_number);
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

	printf("The Pop command was found at line %d\n", line_number);
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

	printf("The Pall command was found at line %d\n", line_number);
}
