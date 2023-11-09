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
	return (0);
}
