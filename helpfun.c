#include "shell.h"

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
