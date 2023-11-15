#include "main.h"

/**
 * _get_path - Searches for the full path of a command in the PATH directories.
 * @parsed_command: The command to search for.
 *
 * Return: A dynamically allocated string containing the full path of
 * the command, or NULL if the command is not found or an error occurs.
 */

char *_get_path(char *parsed_command)
{
	int i = 0;
	char *path_env, *full_cmd, *dir;
	struct stat st;

	for (i = 0; parsed_command[i]; i++)
	{
		if (parsed_command[i] == '/')
		{
			if (stat(parsed_command, &st) == 0)
				return (_strdup(parsed_command));
			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc((_strlen(dir) + _strlen(parsed_command) + 2));
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, parsed_command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd);
			full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
