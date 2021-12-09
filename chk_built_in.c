#include "main.h"

/**
 * _ext - exits the program
 * @tokens: pointer to the tokens
 * @env: pointer to env variables
 * Return: nothing
 */
int _ext(char ***tokens, char **env)
{
	int status = 0;
	(void) tokens;
	(void) env;
	/*free before exiting*/
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
	char *env_pwd = NULL;
	int chdir_status;

	(void) tokens;

	env_home = _getenv("HOME", env);
	env_pwd = _getenv("PWD", env);

	if ((*tokens)[1] == NULL || _strcmp((*tokens)[1], "~") == 0 ||
			_strcmp((*tokens)[1], "$HOME") == 0)
	{
		chdir_status = chdir(env_home);
	}
	if (_strcmp((*tokens)[1], "-") == 0)
		chdir_status = chdir(env_pwd);
	chdir_status = chdir((*tokens)[1]);
	return (chdir_status);
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
		if (_strcmp((*tokens)[0], list[i].op) == 0)
			return (list[i].func(tokens, env));
	}
	return (0);

}
