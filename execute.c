#include "main.h"
/*TODO betty*/


int execute(char *token, char *argv[], char *env[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(token, argv, env); /*TODO handle error, when it returns -1 it means path not found and will return errno,print errno to screen in case of not existence of the path*/
	}
	else
	{
		wait(&status); /* TODO how status works?*/
	}
	return (0);
}
