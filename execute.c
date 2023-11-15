#include "main.h"

/**
 * _execute - Executes a command by forking a new process.
 * @parsed_command: The parsed command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @command_index: The index of the current command in the shell.
 *
 * Return: The exit status of the executed command.
 */

int _execute(char **parsed_command, char **argv, int command_index)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _get_path(parsed_command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], parsed_command[0], command_index);
		free_string_array(parsed_command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, parsed_command, environ) == -1)
		{
			free(full_cmd);
			full_cmd = NULL;
			free_string_array(parsed_command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_string_array(parsed_command);
		free(full_cmd);
		full_cmd = NULL;
	}

	return (WEXITSTATUS(status));
}
