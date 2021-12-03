#include "main.h"
/*TODO betty*/
/**
 * execute - process id and path execution
 * @argv: pointer to the filenames
 * @token: string of path
 * @env : pointer to shell variables
 * Return: always 1 to continue the loop
 */


int execute(char *token, char *argv[], char *env[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	/* i'm the parent process */
	if (child_pid == -1)
	{
		perror("Error: failed process\n");
		return (1);
	} /* i'm the child process */
	if (child_pid == 0)
	{
		execve(token, argv, env);
		printf("Success\n");
		/*TODO handle error, when it returns -1 it means path not found and will return errno,print errno to screen in case of not existence of the path*/
	}
	else
	{
		wait(&status); /* TODO how status works?*/
	}
	return (0);
}
