#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

void sighandler(int);
int my_shell(char **argv, char **env);
int _read(char **buffer);
void _parse(char **buffer, int *token_count, char ***tokens, char ***argv);
int chk_cmd(char ***token, char *argv[], char *env[]);
int execute(char ***token, char *argv[], char *env[]);
int chk_built_in(char ***tokens, char **env);
int add_path(char ***tokens, char **env);
char *_strcat(char *dest, char *src);
char *_getenv(const char *var_env, char **env);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

/**
 * struct opr - a struct that keeps two types of data, a str and a func pointer
 * @op: the operation string that will be used to check builtins
 * @func: a func pointer
 */
typedef struct opr
{
	char *op;
	int (*func)(char ***tokens, char **env);
} opr_t;

/**
 *struct path_node - singly linked list for path
 *@path: string to save each path token
 *@next: next node pointer
 */
typedef struct path
{
	char *path;
	struct path *next;
} path_node;

void free_list(path_node *path_n);

#endif /* MAIN_H */
