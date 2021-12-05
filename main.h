#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void sighandler(int);
int my_shell(char **argv, char **env);
int _read(char **buffer, int *len);
void _parse(char **buffer, int *token_len, char ***tokens);
int execute(char ***token, char *argv[], char *env[]);

#endif /* MAIN_H */
