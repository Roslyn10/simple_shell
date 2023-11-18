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
 * @file: A pointer to a string that represents the file or command
 * @argv: An array of string representing the arguments passed to the command
 * Return: -1
 */

int _execvp(const char *file, char *const argv[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
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

void display_env(void)
{
	int f;
	char *value;
	char *env_vars[] = {
		"USER", "LANGUAGE", "COMPIZ_CONFIG_PROFILE", "C_IS", 
		"DESKTOP_SESSION", "LOGNAME", "TERM", "PATH", "DISPLAY", NULL
	};

	for (f = 0; env_vars[f] != NULL; f++)
	{
		value = getenv(env_vars[f]);
		if (value != NULL)
		{
			printf("%s=%s\n", env_vars[f], value);
		}
	}
}
