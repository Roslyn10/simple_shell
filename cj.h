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

/**
 * buit-in - A function
 * void func_printenv(char **environ);
 */

/**
 * gen_env - A function
 * char **get_environ(ino_t *info);
 * int _unsetenv(ino_t *info, char *var);
 * int _setenv(ino_t *info, char *var, char *value);
 */

/**
 * get_info - A function
 * void clear_info(ino_t *info);
 * void set_info(ino_t *info, char **av);
 * void free_info(ino_t *info, int all);
 */

/**
 * helpfun - A function
 * void new_line(void);
 * int _execvp(const char *file, char *const argv[]);
 */

/**
 * history_file - A function
 * char *get_history_file(ino_t *info);
 * int write_history(ino_t *info);
 * int read_history(ino_t *info);
 * int build_history_list(ino_t *info, char *buf, int linecount);
 * int renumber_history(ino_t *info);
 */

/**
 * lists - A function
 * list_t *add_node(list_t **head, const char *str, int num);
 * list_t *add_node_end(list_t **head, const char *str, int num);
 * size_t print_list_str(const list_t *h);
 * int delete_node_at_index(list_t **head, unsigned int index);
 * void free_list(list_t **head_ptr);
 */

/**mainshell**/
int main(void);

/**
 * memory - A function
 * int bfree(void **ptr);
 */

/**
 * more_list - A function
 * size_t list_len(const list_t *h);
 * char **list_to_strings(list_t *head);
 * size_t print_list(const list_t *h);
 * list_t *node_starts_with(list_t *node, char *prefix, char c);
 * ssize_t get_node_index(list_t *head, list_t *node);
 */

/**
 * parser - A function
 * int is_cmd(ino_t *info, char *path);
 * char *dup_chars(char *pathstr, int start, int stop);
 * char *find_path(ino_t *info, char *pathstr, char *cmd);
 */

/**
 * realloc - A function
 * char *_memset(char *s, char b, unsigned int n);
 * void ffree(char **pp);
 * void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
 */

/**shell**/
void display_prompt(void);
char *read_command(void);
void execute_command(char *command/**, ino_t *info**/);

/**
 * shell_loop
 * int hsh(ino_t *info, char **av);
 * int find_builtin(ino_t *info);
 * void find_cmd(ino_t *info);
 * void fork_cmd(ino_t *info);
 */

/**
 * shell_strings
 * char *_strcpy(char *dest, char *src);
 * char *_strdup(const char *str);
 * void _puts(char *str);
 * int _putchar(char c);
 */

/**string
 * char *starts_with(const char *haystack, const char *needle);
 * char *_strcat(char *dest, char *src);
 */

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
