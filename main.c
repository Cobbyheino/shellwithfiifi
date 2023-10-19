#include "shell.h"
/**
 * main - entry point
 * @ac: arg count
 * @argv: arg vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, idx = 0;
	(void) ac;

	while (1)
	{
		line = get_line();
		if (line == NULL) /*reaches EOF ctrl + D */
		{
			if (isatty(STDIN_FILENO))/*to run noninteractive*/
				write(STDOUT_FILENO, "\n ", 1);/* move to newlin*/
			return (status);
		}
		idx++;
		command = tokenizer(line);/* feeds userinput into tokenizer*/
		if (!command)/*if no command continue the program*/
			continue;
		if (is_builtin(command[0]))
			handle_builtin(command,argv, &status, idx);
		else
	
		status = _execute(command, argv, idx);
	}
}
