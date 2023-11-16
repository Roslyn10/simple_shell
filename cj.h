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
#include <errno.h>

#define MAX_ARGS 100

/**mainshell**/
int main(void);

/**shell**/
void display_prompt(void);
char *read_command(void);
void execute_command(char *command/**, ino_t *info**/);

/**strings**/
int _putchar1(char c);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);

/**tokenizer**/
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);

/**vars**/
int is_chain(ino_t *info, char *buf, size_t *p);
void check_chain(ino_t *info, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(ino_t *info);
int replace_vars(ino_t *info);
int replace_string(char **old, char *new);


#endif /**SHELL_H**/
