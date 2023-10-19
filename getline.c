#include "shell.h"

/**
 * get_line - reads line from user
 * Return: line receives
 */

char *get_line(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t x;

	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);/*to run noninterative*/
	x = getline(&line, &length, stdin);
	if (x == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);

}
