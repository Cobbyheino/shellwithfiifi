#include "shell.h"

char **tokenizer(char *line)
{
	char **array, *pass;
	int i = 0, j = 0;

	array = malloc(8 * sizeof(char *));
	if (array == NULL)
	{
		perror("cant allocate space");
		exit(1);
	}
	pass = strtok(line, " ");
	while (pass != NULL)
	{
		while (pass[j])
		{
			if (pass[j] == '\n')
				pass[j] = '\0';
			j++;
		}
		array[i] = pass;
		i++;
		j = 0;
		pass = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}
