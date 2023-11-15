#include "main.h"

/**
 * main - The entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: The exit status of the shell program.
 */

int main(int argc, char **argv)
{
	char *input_line = NULL;
	char **parsed_command = NULL;
	int status = 0, command_index = 0;
	(void) argc;

	while (1)
	{
		input_line = read_input();

		if (input_line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			return (status);
		}
		command_index++;

		parsed_command = tokenize(input_line);
		if (!parsed_command)
			continue;

		if (is_builtin(parsed_command[0]))
			builtin(parsed_command, argv, &status, command_index);
		else
			status = _execute(parsed_command, argv, command_index);
	}
}
