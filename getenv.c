#include "shell.h"

/**
 * _getenv - returns the strcpy of our environ
 * @vars: contains str variables
 *
 * Return: null
 */

char *_getenv(char *vars)
{
	char *tmp, *k;
	char *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		k = strtok(tmp, "=");
		if (_strcmp(k, vars) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
