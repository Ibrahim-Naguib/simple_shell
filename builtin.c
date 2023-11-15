#include "main.h"

/**
 * is_builtin - Checks if a parsed command is a built-in command.
 * @parsed_command: The parsed command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */

int is_builtin(char *parsed_command)
{
	int i;
	char *builtin_cmds[] = {"exit", "env", NULL};

	for (i = 0; builtin_cmds[i]; i++)
	{
		if (_strcmp(parsed_command, builtin_cmds[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * builtin - Executes a built-in command.
 * @parsed_command: The parsed command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @status: A pointer to the exit status of the shell.
 * @command_idx: The index of the current command in the shell.
 */

void builtin(char **parsed_command, char **argv, int *status, int command_idx)
{
	if (_strcmp(parsed_command[0], "exit") == 0)
		my_exit(parsed_command, argv, status, command_idx);
	else if (_strcmp(parsed_command[0], "env") == 0)
		my_env(parsed_command, status);
}
