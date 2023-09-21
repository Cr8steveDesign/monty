#include "monty.h"
#define __GNU_SOURCE

/**
 * main - Entry Point for the program
 * @argc: Command line argument counter
 * @argv: Array of commandline arguments
 * Return: Always 0 or something
 */

int main(int argc, char **argv)
{
	FILE *fileopen;
	char *buffer = NULL;
	size_t buffsize = 0;
	char *item = NULL;

	char *all_lines[4000] = {NULL};

	char *commands[2] = {NULL, NULL};
	char *token = NULL;

	int line_num = 0;
	int idx = 0;
	int flag = 0;

	stack_t *Our_Stack = NULL;

	instruction_t ops_array[4] = {
		{"push", op_push},
		{"pop", op_pop},
		{"pall", op_pall},
		{NULL, NULL}};

	(void)item;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <filename>\n");
		exit(EXIT_FAILURE);
	}

	fileopen = fopen(argv[1], "r");

	while (getline(&buffer, &buffsize, fileopen) != -1)
	{
		buffer = strtok(buffer, "\n");
		all_lines[line_num] = _strdup(buffer);
		line_num++;
	}
	all_lines[line_num] = NULL;

	/*LINES NOW IN THE ARRAY*/
	while (all_lines[idx] != NULL)
	{
		int i = 0;
		token = strtok(all_lines[idx], " ");
		commands[0] = token;

		/*Get Second token*/
		token = strtok(NULL, " ");
		commands[1] = token;
		item = commands[1];

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
			free(buffer);
			free_arr(all_lines);
			fclose(fileopen);
			exit(EXIT_FAILURE);
		}

		idx++;
	}

	free(buffer);
	free_arr(all_lines);
	fclose(fileopen);

	return (0);
}

void free_arr(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
}

void print_testign(char **array)
{
	int i = 0;
	/*Print the lines in the array*/
	while (array[i])
	{
		printf("Line: %d is : %s", i + 1, array[i]);
		i++;
	}
}
