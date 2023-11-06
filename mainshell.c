#include "shell.c"

/**
 * main - Implements the loop and makes sure that it can run indefinetly
 * Description - Makes sure that the loop runs indefinetly. Exitloop with Ctrl+D
 * Aditional info - Create a printf function/printing function
 * Return: 0 Always (Success)
 */

int main(void)
{
        if (isatty(STDIN_FILENO))
        {
                while (1) /**Allows the command to loop indefinetly**/
                {
                        char *command = read_command(); /**Reads command from the user**/

                        if (command == NULL)
                        {
                                new_line(); /**Used to print a new line**/
                                exit(1); /**EOF = Ctrl+D**/
                        }

                        execute_command(command); /**Executes user command/input**/
                        free(command); /**Frees the memory allocated to the command/input**/
                }
        }

        return (0);
}
