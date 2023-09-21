#include "monty.h"

/**
 * error_not_found
 * @all_lines:lines array to free
 * @idx:line number
 * @commands: command not found
 */

void error_not_found(char **all_lines, int idx, char *commands)
{
	printf("L%d: %s not found\n", idx + 1, commands);
	free_arr(all_lines);
	exit(EXIT_FAILURE);
}
