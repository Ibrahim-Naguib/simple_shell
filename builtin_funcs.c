#include "main.h"

/**
 * my_exit - Exits the shell with a specified exit value.
 * @parsed_command: The parsed command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @status: A pointer to the exit status of the shell.
 * @command_idx: The index of the current command in the shell.
 *
 * Return: void.
 */

void my_exit(char **parsed_command, char **argv, int *status, int command_idx)
{
	int exit_value = (*status);
	char *index, msg[] = ": exit: Illegal number: ";

	if (parsed_command[1])
	{
		if (is_positive_num(parsed_command[1]))
		{
			exit_value = _atoi(parsed_command[1]);
		}
		else
		{
			index = _itoa(command_idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, parsed_command[1], _strlen(parsed_command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free_string_array(parsed_command);
			(*status) = 2;
			return;
		}
	}
	free_string_array(parsed_command);
	exit(exit_value);
}

/**
 * my_env - Prints the environment variables.
 * @parsed_command: The parsed command and its arguments.
 * @status: A pointer to the exit status of the shell.
 *
 * Return: void.
 */

void my_env(char **parsed_command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_string_array(parsed_command);
	(*status) = 0;
}
