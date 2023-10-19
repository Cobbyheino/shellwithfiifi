#include "shell.h"
/**
 * _getpath - gets path from envin
 * @command: command to find path
 *
 * Return: null
 */
char *_getpath(char *command)
{
	char *env_path, *full_cmd, *dirx;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)/* setting path in env*/
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)/*if there is path*/
			return (_strdup(command));
			return (NULL);
		}
	}
	env_path = _getenv("PATH");/* if the path is unset path*/
	if (!env_path)
		return (NULL);
	dirx = strtok(env_path, ":");/* handle the path*/
	while (dirx)
	{
		full_cmd = malloc(_strlen(dirx) + _strlen(command) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dirx);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(env_path);
				return (full_cmd);
			}
		free(full_cmd), full_cmd = NULL;
		dirx = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}
