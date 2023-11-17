#include "cj.h"

/**
 * read_from_file - 
 * Description - 
 * @script:
 * Return:
 */

char *read_from_file(FILE *script)
{
	char *input = NULL;
	size_t length = 0;
	ssize_t bread;

	bread = getlline(&input, &length, script);

	if (bread == -1)
	{
		free(input);
		return (NULL);
	}

	if (bread > 0 && input[bread - 1] == '\n')
	{
		input[bread - 1] = '\0';
	}

	return (input);
}

/**
 * non_int - 
 * Desription - 
 * @script:
 * Return:
 */

void non_int(FILE *script)
{
	char *command;

	while ((command = read_from_file(script)) != NULL)
	{
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}

		execute_command(command);
		free(command);
	}
}

/**
 * main - Implements the loop and makes sure that it can run indefinetly
 * Description - Makes sure that it runs indefinetly. Exit loop with Ctrl+D
 * Return: 0 Always (Success)
 */

int main(void)
{
	char *command;
	int result;

	if (argc > 1)
	{


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

			result = chdir("/path/to/directory");

			if (result == 0)
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(1);
			}

			if (_strcmp(command, "exit ") == 0)
			{
				free(command);
				break;
			}

			execute_command(command/**, &info**/);
			free(command);
		}
	}
	return (0);
}
