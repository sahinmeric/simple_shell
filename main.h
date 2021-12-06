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
int _read(char **buffer, int *len);
void _parse(char **buffer, int *token_len, char ***tokens);
int chk_cmd(char ***token, char *argv[], char *env[]);
int execute(char ***token, char *argv[], char *env[]);
int chk_built_in(char *** tokens, char **env);
int add_path(char ***tokens, char **env);
char *_strcat(char *dest, char *src);

/**TODO
 *
 *
 *
 */
typedef struct opr
{
	char *op;
	int (*func)(char ***tokens, char **env);
}opr_t;

/**TODO
 *
 *
 */
typedef struct path
{
	char *path;
	struct path *next;	
} path_node;

#endif /* MAIN_H */
