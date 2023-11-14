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

/**Main shell code**/
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
int main(void);

/**Prints a new line after exiting the code**/
void new_line(void);

/** Used instead of printf**/
int _putchar(char c);

/** String functions**/
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);

/**helpful functions**/
int _execvp(const char *file, char *const argv[]);

/** Buffers chained commands**/
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/** Initializing environment**/
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/** gen_env.c**/
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/** history_file.c**/
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/** more_lists.c**/
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/** toem_vars.c**/
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/**toem_string.c**/
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/** toem_strings.c**/
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);



#endif /**SHELL_H**/
