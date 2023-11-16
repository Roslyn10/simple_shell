#include "cj.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - A function that calculates the lenght of a string
 * Description - Calculates length of string and returns number of characters
 * @str: Input/Given string
 * Return: The lenght of the string
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	if (!str)
	{
		return (0);
	}

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcmp - A function that compares two strings character by character
 * Description - Compares two strings character by character
 * @s1: First string
 * @s2: Second string
 * Return: 0 Always (Success)
 */

int _strcmp(const char *s1, const char *s2)
{
	int index = 0;

	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
	}
	return (s1[index] - s2[index]);
}

/**
 * _strtok - A function that tokenizers strings
 * Description - Breaks a string into smaller pieces
 * @str: Input string
 * @delim: String containing characters that are delimiters
 * Return: start of the sting
 */

char *_strtok(char *str, const char *delim)
{
	static char *lastok;
	char *start;
	char *end;

	lastok = NULL;
	if (str != NULL)
	{
		lastok = str;
	}
	else
	{
		if (lastok == NULL)
			return (NULL);
	}
	start = lastok;
	while (*start != '\0' && _strchr(delim, *start) != NULL)
	{
		start++;
	}
	if (*start == '\0')
	{
		lastok = NULL;
		return (NULL);
	}

	end = start;
	while (*end != '\0' && _strchr(delim, *end) == NULL)
	{
		end++;
	}
	if (*end != '\0')
	{
		*end = '\0';
		lastok = end + 1;
	}
	else
	{
		lastok = NULL;
	}
	return (start);
}

/**
 * _strchr - A function that is used to find the first occurence of a speific
 * character
 * Desription - Finds the first ocurence of a char
 * @str: A pointer to the null-term string
 * @ch: The character the code is searching for
 * Return: THe character if it is found or NULL if not
 */

char *_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}

	return (NULL);
}
