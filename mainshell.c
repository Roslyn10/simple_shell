#include "cj.h"

/**
 * main - Implements the loop and makes sure that it can run indefinetly
 * Description - Makes sure that it runs indefinetly. Exit loop with Ctrl+D
 * Aditional info - Create a printf function/printing function
 * Return: 0 Always (Success)
 */

int main(void)
{
	char *command;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			command = read_command();

			if (command == NULL)
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(1);
			}

			if (strcmp(command, "exit") == 0)
			{
				free(command);
				break;
			}

			execute_command(command);
			free(command);
		}
	}
	return (0);
}
