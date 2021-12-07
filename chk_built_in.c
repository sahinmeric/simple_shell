#include "main.h"

/**TODO
 *
 *
 *
 */
int _ext(char ***tokens, char **env)
{
	int status = 1; /*TODO pass status to this func*/
	(void) tokens;
	(void) env;
	exit(status); /*and exit*/
}

/**
 *
 *
 *
 */
int _cd(char ***tokens, char **env)
{
	char *env_home = NULL;
	(void) tokens;
	(void) env;

	env_home = getenv("HOME"); /*TODO wrote your own getenv*/ /*TODO how to handle cd parameters like cd /root/simple_shell ?*/
	chdir(env_home);/*TODO error handle return 0 if success, if fail returns -1 with errno*/
	return (1);
}

/**TODO
 *
 *
 *
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

/**TODO
 *
 *
 *
 *
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
