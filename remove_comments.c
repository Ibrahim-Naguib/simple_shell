#include "main.h"

/**
 * remove_comments - Removes comments from an input line.
 * @input_line: The input line containing a potential comment.
 *
 * Return: A pointer to the modified input line without comments,
 *         or NULL if the entire line is a comment.
 */

char *remove_comments(char *input_line)
{
	char *comment;

	if (input_line[0] == '#')
	{
		free(input_line);
		return (NULL);
	}

	comment = _strstr(input_line, " #");
	if (comment != NULL)
		*comment = '\0';

	return (input_line);
}
