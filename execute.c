#include "shell.h"

int _execute(char **command, char  **argv, int idx)

{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		free(command), command = NULL;
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free(command), command = NULL;
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(command), command = NULL;
		free(full_cmd), full_cmd = NULL;
	}
	free(command);
	return(WEXITSTATUS(status));
}
