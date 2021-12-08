#include "main.h"

/**
 * _getenv - gets env values
 * @var_env:  env variable that will be searched
 * @env: pointer to env variables
 * Return: var_env's value, NULL otherwise
 */
char *_getenv(const char *var_env, char **env)
{
	int i, j, flag = 1;

	if (env == NULL)
		return (NULL);
	for (i = 0; env[i] != NULL; i++, flag = 1)
	{
		for (j = 0; env[i][j] != '='; j++)
		{
			if (var_env[j] != env[i][j])
			{
				flag = 0;
				break;
			}
		}
		if (flag != 0)
			return (&(env[i][j + 1]));
	}
	return (NULL);
}
