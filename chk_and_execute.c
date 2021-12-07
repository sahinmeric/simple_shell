#include "main.h"

/**TODO
 *
 *
 *
 *
 */
int chk_cmd(char ***tokens, char **argv, char **env)
{	int status_builtin;
	char tkn = *tokens[0][0];
	/*Check if it is built in*/

	status_builtin = chk_built_in(tokens, env);

	if (status_builtin == 0) /* it means it is not builtin*/
	{
		/*Check if it has a path */
		if (tkn == '/' || tkn == '.')
		{
			execute(tokens, argv, env);
			return (0);
		}
		else
		{
			/*Append path to cmd */
			add_path(tokens, env);
			/*Execute with path + cmd */
			execute(tokens, argv, env);
		}
	}
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
	int status; /*we need for wait func*/
	char *cmd = **tokens; /*a pointer to first byte of first token*/

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: "); /*perror will add a string of occured error*/
		return (1);
	}
	if (child_pid == 0) /*if child_pid is == 0 it means it is child process and will execute this block*/
	{
		if (execve(cmd, argv, env) == -1)
		{
			free(cmd);
			exit(0);
		}
		/*TODO handle error, when it returns -1 it means path not found and will return errno,print errno to screen in case of not existence of the path*/
	}
	else /*Else block will be executed by parent process*/
	{
		wait(&status);
	}
	return (0);
}
