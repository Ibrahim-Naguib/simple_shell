#include "main.h"

/**
 * read_input - Reads a line of input from the user.
 *
 * Return: A pointer to the allocated buffer containing the input line,
 *         or NULL on failure or if the end of input is reached.
 */

char *read_input(void)
{
	char *buff = NULL;
	size_t buffer_size = 0;
	ssize_t line;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	line = getline(&buff, &buffer_size, stdin);

	if (line == -1)
	{
		free(buff);
		return (NULL);
	}

	return (buff);
}
