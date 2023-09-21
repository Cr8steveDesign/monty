#include "monty.h"

/**
 * read_lines - Reads all lines from file
 * @argv: Name of file from command line
 * Return: An array of all lines
 */

char **read_lines(char *argv)
{

	int len = count_lines(argv);
	char **all_lines1 = NULL;

	all_lines1 = load_lines(argv, len);

	return (all_lines1);
}

/**
 * count_lines - Returns the number of lines
 * @argv: Name of file from command line
 * Return: Void always
 */

int count_lines(char *argv)
{
	FILE *fileopen;
	size_t buffsize = 0;
	char *buffer = NULL;
	int len = 0;

	fileopen = fopen(argv, "r");

	while (getline(&buffer, &buffsize, fileopen) != -1)
	{
		buffer = strtok(buffer, "\n");
		if (buffer != NULL)
			len++;

		free(buffer);
		buffer = NULL;
	}

	free(buffer);
	buffer = NULL;

	fclose(fileopen);
	return (len);
}

/**
 * load_lines - Loads an array with strings
 *
 * Return: Alway
 */

char **load_lines(char *argv, int len)
{
	FILE *fileopen;
	size_t buffsize = 1;
	ssize_t ch_r = 0;
	char *buffer = NULL;
	char **all_lines = NULL;
	int line_num = 0;

	printf("%d: Lines\n", len);
	fileopen = fopen(argv, "r");

	all_lines = malloc(sizeof(char *) * (len + 1));
	fileopen = fopen(argv, "r");

	while ((ch_r = getline(&buffer, &buffsize, fileopen)) != -1)
	{
		buffer = strtok(buffer, "\n");
		if (buffer != NULL)
		{
			all_lines[line_num] = _strdup(buffer);
			line_num++;
		}
		else
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		free(buffer);
		buffer = NULL;
	}

	all_lines[line_num] = NULL;
	fclose(fileopen);

	if (ch_r == -1)
		free(buffer);

	return (all_lines);
}
