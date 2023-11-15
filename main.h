#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \t\n;"
extern char **environ;

char *read_input(void);
char **tokenize(char *line);
int _execute(char **args, char **argv, int idx);

char *_getenv(char *name);
char *_get_path(char *command);
void print_error(char *name, char *cmd, int idx);

int is_builtin(char *command);
void builtin(char **command, char **argv, int *status, int idx);
void my_exit(char **command, char **argv, int *status, int idx);
void my_env(char **command, int *status);
char *remove_comments(char *input_line);

void free_string_array(char **arr);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, int c);
void reverse_string(char *str, int len);

char *_itoa(int n);
int _atoi(char *str);
int is_positive_num(char *str);

#endif
