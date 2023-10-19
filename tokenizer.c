#include "shell.h"

/**
 * tokenizer - splits str to words
 * @line: input
 * Return: tokenized input
 */

char **tokenizer(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
	char **command = NULL;
	int tok = 0, i = 0;

	if (!line)/*if no line return null*/
		return (NULL);
	tmp = _strdup(line);

	token = strtok(tmp, DELIM);/*if space is typed*/
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		tok++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (tok + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = _strdup(token);/*token accepted to comd*/
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
