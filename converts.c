#include "main.h"

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n = n / 10;
		}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (_strdup(buffer));
}

/**
 * _atoi - Converts a string to an integer.
 * @str: The string to convert.
 *
 * Return: The converted integer.
 */

int _atoi(char *str)
{
	int i = 0, num = 0;

	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

/**
 * is_positive_num - Checks if a string represents a positive number.
 * @str: The string to check.
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */

int is_positive_num(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
