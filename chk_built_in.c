#include "main.h"
/**
 *
 *
 *
 */
int _env(char ***tokens, char **env)
{
	int i, j;

	for (i = 0; env[i] != NULL ; i++)
		{
			for (j = 0; env[i][j] != '\0'; j++)
				; /*counting the length of each string*/

				write(1, env[i], j); /*write the env variable and its value*/
				write(1, "\n", 1); /*write new line*/
		}
	return (0);
}




/**
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
		{NULL, NULL}
	};
	for (i = 0; list[i].op != NULL; i++)
	{
		if (strcmp((*tokens)[0], list[i].op) == 0)
			return (list[i].func(tokens, env));
	}
	return (0);

}
