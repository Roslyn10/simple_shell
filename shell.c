#include "shell.h"

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

/**
 * display_prompt - A function that displays the '$' prompt
 * Description - Displays the '$' prompt at the beginning of the line
 * Return: Nothing
 */

void display_prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * read_command - A function that reads the input/command that the user types
 * Description - Reads the command inserted by the user
 * Return: The input
 */

char *read_command(void)
{
	char *input = NULL;
	size_t length = 0;
	int bread;

	display_prompt();

	bread = getline(&input, &length, stdin);

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
 * execute_command - A function that executes the command/ input given by user
 * Description - Executes the command/input inerted by the user
 * @command: Command/input from user
 * Return: Nothing
 */

void execute_command(char *command)
{
	pid_t child_pid;
	int status;
	char *args[MAX_ARGS];
	int arg_count = 0;
	const char *error_msg = "Error: No command provided \n";
	const char *error = "Error: Fork failed\n";
	const char *msg = "Error: Execution failed\n";
	char *token;

	token = strtok(command, " ");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (arg_count == 0)
	{
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		return;
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		write(STDERR_FILENO, error, _strlen(error));
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			write(STDERR_FILENO, msg, _strlen(msg));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
