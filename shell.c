#include "cj.h"

void display_prompt(void);
char *read_command(void);
void execute_command(char *command/**, ino_t *info**/);


/**
 * display_prompt - A function that displays the 'CJ' prompt
 * Description - Displays the 'CJ' prompt at the beginning of the line
 * Return: Nothing
 */

void display_prompt(void)
{
	char *prompt = "Command-Justice ";

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
	static int shell_count;
	pid_t child_pid;
	/**char *envp[MAX_ARGS];**/
	int status;
	char *args[MAX_ARGS];
	int arg_count = 0;
	const char *error = "Error: Fork failed\n";
	/**const char *msg_pre = "hsh: ";**/
	/**const char *msg_suf = ": not found\n";**/
	char *token;

	shell_count = 0;
	shell_count++;
	token = _strtok(command, " ");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (arg_count == 0)
	{
		return;
	}

	if (_strcmp(args[0], "cd") == 0)
	{
		if (arg_count > 1)
		{
			if (chdir(args[0]) != 0)
			{
				return;
			}
		}
	}


	child_pid = fork();

	if (child_pid == -1)
	{
		write(STDERR_FILENO, error, _strlen(error));
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execvp(args[0], args/**, envp**/) == -1)
		{
			/**_puts(msg_pre);**/
			/**_puts(itoa(shell_count));**/
			/**_puts(": ");**/
			/**_puts(args[0]);**/
			/**_puts(msg_suf);**/

			printf("hsh: %d: %s: not found\n", shell_count, command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
