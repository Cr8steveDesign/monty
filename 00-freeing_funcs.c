#include "monty.h"

/**
 * free_arr - Frees a 2D Array of Srings
 * @array: Pointer to the head of the stack
 * Return: Void;
 */
void free_arr(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * free_stack - Frees a 2D Array of Srings
 * @stack: Pointer to the head of the stack
 * Return: Void;
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
