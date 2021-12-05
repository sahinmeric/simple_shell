#include "main.h"

/**TODO
 *
 *
 *
 *
 */
int chk_cmd(char ***tokens, char **argv, char **env)
{
	/*Check if it is built in*/
	chk_built_in(tokens, env);

	/*Check if it has a path */

	return (0);
}







/**TODO
 * execute - process id and path execution
 * @argv: pointer to the filenames
 * @tokens: tokens
 * @env : pointer to shell variables
 * Return: always 1 to continue the loop
 */


int execute(char ***tokens, char *argv[], char *env[])
{
	pid_t child_pid;
	int status;
	char *cmd = **tokens;

	/*Check command before fork*/
	chk_cmd(tokens, argv, env);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: failed process\n");
		return (1);
	}
	if (child_pid == 0) /*if child_pid is == 0 it means it is child process and will execute this block*/
	{
		printf("cmd is : %s\n", cmd);
		execve(cmd, argv, env);
		/*TODO handle error, when it returns -1 it means path not found and will return errno,print errno to screen in case of not existence of the path*/
	}
	else /*Else block will be executed by parent process*/
	{
		wait(&status);
	}
	return (0);
}
