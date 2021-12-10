#include "main.h"

/**
* _strcat - concats two strings.
* @dest: destination char pointer.
* @src: source char pointer
* Return: a char pointer to destination
*/

char *_strcat(char *dest, char *src)
{
	int n, l;

	n = 0;

	while (dest[n])
		n++;

	for (l = 0; src[l] != '\0'; l++)
	{
		dest[n] = src[l];
		n++;
	}

		return (dest);
}

/**
 *_strdup -  returns a pointer to a newly allocated space in memory, which
 *contains a copy of the string given as a parameter
 *@str: the string to be copied
 *Return: a pointer to the array or NULL if the process fails
 */
char *_strdup(char *str)
{
	int i, len;
	char *a;

	if (str == 0)
	{
		return (0);
	}
	for (len = 0; str[len] != 0; len++)
	{
	}
	len++;
	a = malloc(sizeof(char) * len);
	if (a == 0)
	{
		return (0);
	}
	for (i = 0; i <= len; i++)
	{
		a[i] = str[i];
	}
	return (a);
}

/**
 *_strcmp - compares two strings and tells whether they are greater than, less
 *than, or equal
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: result of subtraction between the two strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int res;

	while (s1[i] != 0 && s2[i] != 0)
	{
		res = s1[i] - s2[i];
		if (res == 0)
		{
			i++;
		}
		else
		{
			break;
			return (res);
		}
	}
	return (res);
}

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
