#include "cj.h"

/**
 * new_line - A function that prints a new line
 * Description _ prints a new line wothout using printf
 * Return: Nothing
 */

void new_line(void)
{
	const char n_l[] = "\n";

	write(STDOUT_FILENO, n_l, sizeof(n_l) - 1);
}

/**
 * cd _ A function that changes directoris
 * Description - Should work like the cd command
 * return: 0 Always (Success)
 */

