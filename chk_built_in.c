#include "main.h"
/**
 *
 *
 *
 */
int _env(char ***tokens, char **env)
{
	printf("env var found\n");
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
