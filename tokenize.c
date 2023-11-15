#include "main.h"

/**
 * tokenize - Splits an input line into tokens.
 * @input_line: The input line to tokenize.
 *
 * Return: An array of pointers to tokens, or NULL on failure.
 */

char **tokenize(char *input_line)
{
	char *token = NULL, *temp = NULL, **args = NULL;
	int i = 0, count = 0;

	input_line = remove_comments(input_line);
	if (!input_line)
		return (NULL);

	temp = _strdup(input_line);
	token = strtok(temp, DELIM);
	if (token == NULL)
	{
		free(input_line), input_line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(temp), temp = NULL;
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
	{
		free(input_line);
		input_line = NULL;
		return (NULL);
	}
	token = strtok(input_line, DELIM);
	while (token)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(input_line), input_line = NULL;
	args[i] = NULL;
	return (args);
}
