#include "main.h"

/**
 * print_error - Prints a command not found error message to standard error.
 * @name: The name of the shell program.
 * @parsed_command: The command that was not found.
 * @command_index: The index of the command in the shell.
 */

void print_error(char *name, char *parsed_command, int command_index)
{
	char *index, msg[] = ": not found\n";

	index = _itoa(command_index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, parsed_command, _strlen(parsed_command));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}
