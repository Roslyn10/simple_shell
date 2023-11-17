#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>

#define MAX_ARGS 100

/**helpfun**/
void new_line(void);
int _execvp(const char *file, char *const argv[]);
void display_env(void);

/**mainshell**/
int main(void);

/**shell**/
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

/**strings**/
int _putchar(char c);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);


#endif /**SHELL_H**/
