#include "main.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: A dynamically allocated string containing the value of the variable,
 *         or NULL if the variable is not found.
 */

char *_getenv(char *name)
{
	int i = 0;
	char *temp, *key, *value, *env;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strcmp(key, name) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(temp);
			return (env);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}
