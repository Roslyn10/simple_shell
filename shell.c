#include "shell.h"

/**
 * display_prompt - A function that displays the '$' prompt
 * Description - Displays the '$' prompt at the beginning of the line
 * Return: Nothing
 */

void display_prompt(void)
{
	char *prompt = "simple_shell$ ";
	write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * read_command - Afunction that reads the input/command that the user types
 * Description - Reads the command inserted by the user
 * Return: The input
 */

char *read_command(void)
{
	char* input = NULL; /**input/command, declares a pointer to hold the user input**/
	size_t length = 0; /**length of input/command initialized to 0**/
	ssize_t bread; /**a variable to store the number of bytes read**/

	display_prompt(); /**Calls the fucntion to display the command prompt**/

	bread = getline(&input, &length, stdin); /**Reads the line/input from the user**/

	if (bread == -1)
	{
		free(input); /**If getline fails, frees the memory allocated for input/command**/
		return (NULL); /**Returns NUll to indicate an error/ end of input*/
	}

	if (bread > 0 && input[bread - 1] == '\n')
	{
		input[bread - 1] = '\0';/**if the input contains the '\n', it gets replaced with '\0'**/
	}

	return (input); /**Returns the users input**/
}

/**
 * execute_command - A function that executes the command/ input given by the user
 * Description - Executes the command/input inerted by the user
 * @command - Command/input from user
 * Return: Nothing
 */

void execute_command(char* command)
{
	pid_t Process_id; /**process id**/
	char* arg[MAX_ARGS]; /**strings for command arguments**/
	int status; /**Stores the exit status of the child process**/
	char* argv[MAX_ARGS]; /**Tokenizes the command and stroes it in the arg array**/
	int argc;

	if (command == NULL || command[0] == '\0')
	{
		perror("NO command\n"); /**Prints an error message if there is no command inserted**/
		return;
	}

	Process_id = fork(); /**Creates a child process**/

	if (Process_id == -1)
	{
		perror("Fork failed");/**Prints an error message if forking failed**/
		exit(EXIT_FAILURE);/**Failure staus, exits the program**/
	}
	else if (Process_id == 0)
	{
		split_toke(command, argv, &argc);

		execve(argv[0], arg, NULL);/**executes the user's command**/

		perror("Execution failed"); /**Prints an error message if the execution fails**/
		exit(EXIT_FAILURE);/**exits the processs with failure status**/
	}
	else
	{
		wait(&status); /**Waits for the child process to finish**/
	}
}
