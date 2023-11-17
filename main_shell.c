#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 64

void display_prompt(void)
{
    char *prompt = "Command-Justice ";

    write(STDOUT_FILENO, prompt, strlen(prompt));
}

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
        return NULL;
    }

    if (bread > 0 && input[bread - 1] == '\n')
    {
        input[bread - 1] = '\0';
    }

    return input;
}

char *read_command_from_file(FILE *script)
{
    char *input = NULL;
    size_t length = 0;
    ssize_t bread;

    bread = getline(&input, &length, script);

    if (bread == -1)
    {
        free(input);
        return NULL;
    }

    if (bread > 0 && input[bread - 1] == '\n')
    {
        input[bread - 1] = '\0';
    }

    return input;
}

void execute_command(char *command)
{
    char *args[MAX_ARGS];
    int arg_count = 0;
    char *token;

    token = strtok(command, " ");

    while (token != NULL)
    {
        if (strcmp(token, "<") == 0)
        {
            // Input redirection
            token = strtok(NULL, " ");
            if (token == NULL)
            {
                fprintf(stderr, "Error: Missing filename after '<'\n");
                return;
            }

            // Open the file for reading
            FILE *file = fopen(token, "r");
            if (file == NULL)
            {
                perror("Error opening file");
                return;
            }

            // Redirect input from the file
            dup2(fileno(file), STDIN_FILENO);
            fclose(file);
        }
        else if (strcmp(token, "|") == 0)
        {
            // Pipe
            token = strtok(NULL, " ");
            if (token == NULL)
            {
                fprintf(stderr, "Error: Missing command after '|'\n");
                return;
            }

            int pipefd[2];
            if (pipe(pipefd) == -1)
            {
                perror("Pipe failed");
                exit(EXIT_FAILURE);
            }

            int pid = fork();

            if (pid == -1)
            {
                perror("Fork failed");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                // Child process: Redirect output to the write end of the pipe
                close(pipefd[0]);
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);

                execute_command(token);
                exit(EXIT_SUCCESS);
            }
            else
            {
                // Parent process: Redirect input from the read end of the pipe
                close(pipefd[1]);
                dup2(pipefd[0], STDIN_FILENO);
                close(pipefd[0]);

                waitpid(pid, NULL, 0);
            }
        }
        else
        {
            // Regular command
            args[arg_count++] = token;
        }

        token = strtok(NULL, " ");
    }

    // Null-terminate the args array
    args[arg_count] = NULL;

    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        // Child process
        if (execvp(args[0], args) == -1)
        {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Parent process
        waitpid(child_pid, NULL, 0);
    }
}

int main(int argc, char *argv[])
{
    char *command;
    int result;

    if (argc > 1)
    {
        FILE *script = fopen(argv[1], "r");

        if (script == NULL)
        {
            perror("Error opening script file");
            return 1;
        }

        while ((command = read_command_from_file(script)) != NULL)
        {
            if (strcmp(command, "exit") == 0)
            {
                free(command);
                break;
            }

            execute_command(command);
            free(command);
        }

        fclose(script);
    }
    else if (isatty(STDIN_FILENO))
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

    return 0;
}
