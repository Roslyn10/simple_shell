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

/**Main shell code**/
void display_prompt(void);

/**Prints a new line after exiting the code**/
void new_line(void);

/** Used instead of printf**/
int _puctchar(char c);

/** String functions**/
size_t _strlen(const char *str);


#endif /**SHELL_H**/
