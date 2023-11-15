#include "main.h"

/**
 * free_string_array - Frees memory allocated for a string array.
 * @arr: The string array to free.
 */

void free_string_array(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
}
