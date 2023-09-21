#include "monty.h"

/**
 * main - Entry Point for the program
 * @argc: Command line argument counter
 * @argv: Array of commandline arguments
 * Return: Always 0 or something
 */

int main(int argc, char **argv)
{
	char **all_lines = NULL;
	char *commands[2] = {NULL, NULL}, *token = NULL;
	int idx = 0, flag = 0, i = 0;
	stack_t *Our_Stack = NULL;

	instruction_t ops_array[] = {
		{"push", op_push},
		{"pop", op_pop},
		{"pall", op_pall},
		{"pint", op_pint},
		{NULL, NULL}};

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <filename>\n");
		exit(EXIT_FAILURE);
	}

	glob.TOS1 = -99, all_lines = read_lines(argv[1]);
	/*LINES NOW IN THE ARRAY*/
	/*
	while (all_lines[idx] != NULL)
	{
		i = 0, token = strtok(all_lines[idx], " ");
		commands[0] = token;
		token = strtok(NULL, " ");
		commands[1] = token, glob.arg = commands[1];

		for (i = 0; ops_array[i].opcode != NULL; i++)
		{
			flag = 0;
			if (strcmp(commands[0], ops_array[i].opcode) == 0)
			{
				ops_array[i].f(&Our_Stack, idx + 1);
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			printf("L%d: %s not found\n", idx + 1, commands[0]);
			free_arr(all_lines);
			exit(EXIT_FAILURE);
		}
		idx++;
	}
	*/
	free_arr(all_lines);
	/*free_stack(&Our_Stack);*/
	return (0);
}

/***********************************************************************
 * ********************************************************************
 * FREEING FUNCTIONS FOR THE STACK AND LINE ARRAYS
 */

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
