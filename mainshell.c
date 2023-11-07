#include "shell.c"

/**
 * main - Implements the loop and makes sure that it can run indefinetly
 * Description - Makes sure that the loop runs indefinetly. Exitloop with Ctrl+D
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

			execute_command(command);
			free(command);
		}
	}
	return (0);
}
