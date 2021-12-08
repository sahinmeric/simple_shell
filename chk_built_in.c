#include "main.h"

/**
 * _ext - exits the program
 * @tokens: pointer to the tokens
 * @env: pointer to env variables
 * Return: nothing
 */
int _ext(char ***tokens, char **env)
{
	int status = 1;
	(void) tokens;
	(void) env;
	exit(status);
}

/**
 * _cd - change directory to home or given path
 * @tokens: pointer to the tokens
 * @env: pointer to env variables
 * Return: 1
 */
int _cd(char ***tokens, char **env)
{
	char *env_home = NULL;
	(void) tokens;
	(void) env;

	env_home = _getenv("HOME", env);
	/*TODO wrote your own getenv*/
	/*TODO how to handle cd parameters like cd /root/simple_shell ?*/
	chdir(env_home);
	/*TODO error handle return 0 if success, if fail returns -1 with errno*/
	return (1);
}

/**
 * _env - print env variables
 * @tokens: pointer to the tokens
 * @env: pointer to env variables
 * Return: 0 on success
 */
int _env(char ***tokens, char **env)
{
	int i, j;

	(void) tokens;

	for (i = 0; env[i] != NULL ; i++)
		{
		for (j = 0; env[i][j] != '\0'; j++)
		; /*counting the length of each string*/

		write(1, env[i], j); /*write the env variable and its value*/
		write(1, "\n", 1); /*write new line*/
		}
	return (1);
}

/**
 * chk_built_in - checks if it is built in, if it is it calls relevant func
 * @tokens: pointer to the tokens
 * @env: pointer to env variables
 * Return: 0 on success
 */
int chk_built_in(char ***tokens, char **env)
{
	int i;

	opr_t list[] = {
		{"env", _env},
		{"cd", _cd},
		{"exit", _ext},
		{NULL, NULL}
	};
	for (i = 0; list[i].op != NULL; i++)
	{
		if (strcmp((*tokens)[0], list[i].op) == 0)
			return (list[i].func(tokens, env));
	}
	return (0);

}
