#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int my_shell(char **argv, char **env);
void sighandler(int);
int execute(char *token, char *argv[], char *env[]);

#endif /* MAIN_H */
