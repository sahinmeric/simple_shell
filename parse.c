#include "main.h"

/**
* _parse - parses buffer into tokens
* @buffer: buffer
* @tokens: pointer to token
* @token_count: token count
* @argv: argument vectors
* Return: nothing
*/

void _parse(char **buffer, int *token_count, char ***tokens, char ***av)
{
	char *tkn, *bff, *token;
	int i = 0, j = 0;
	const char delims[] = " \t\n";

	bff = strdup(*buffer);

	tkn = strtok(bff, delims);
	for (i = 0; tkn != NULL; i++)
	{
		tkn = strtok(NULL, delims);
	}

	*token_count = i;

	*tokens = malloc(sizeof(char *) * (i + 1));
	if (*tokens == NULL)
	{
		perror("Error :");
		return;
	}

	token = strtok(*buffer, delims);
	for (j = 0; token != NULL; j++)
	{
	(*tokens)[j] = token;
	(*av)[j] = token;
	token = strtok(NULL, delims);
	}

	(*tokens)[j] = token;
	(*av)[j] = token;

	free(bff);
}
