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
 * _execvp - A function used for process execution, which replaces the current.
 * . process image with a new one
 * Desription - Replaces the program with a speified one
 *
 */

int _execvp(const char *file, char *const argv[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		printf("Im over hear");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execvp(file, argv) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			return (-1);
		}
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (-1);
		}
	}
	return (-1);
}
