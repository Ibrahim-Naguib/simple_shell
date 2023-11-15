#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be concatenated.
 *
 * Return: A pointer to the resulting string (dest).
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * reverse_string - Reverses a string.
 * @str: The string to be reversed.
 * @len: The length of the string.
 *
 */

void reverse_string(char *str, int len)
{
	int i = 0, j = len - 1;
	char temp;

	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

/**
 * _strstr - Locates the first occurrence of a substring in a string.
 * @haystack: The string to search within.
 * @needle: The substring to search for.
 *
 * Return: A pointer to the first occurrence of the substring in the string,
 *         or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		const char *h = haystack;
		const char *n = needle;

		while (*h == *n && *n != '\0')
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return ((char *)haystack);
		}

		haystack++;
	}

	return (NULL);
}
