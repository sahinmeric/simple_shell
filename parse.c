#include "main.h"

/**
* _parse - parses buffer into tokens
* @buffer: buffer
* @tokens: pointer to token
* @token_count: token count
* @argv: argument vectors
* Return: nothing
*/
void _parse(char **buffer, int *token_count, char ***tokens, char ***argv)
{
	char *token;
	int i;
	const char delim[] = " \t\n";

	*tokens = malloc(sizeof(char *) * (*token_count + 1));
	if (*tokens == NULL)
	{
		printf("Error\n");
		return;
	}
	token = strtok(*buffer, delim);
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token; /* set tokens[i] to current token*/
		token = strtok(NULL, delim); /*set current token to next token*/
	}
	(*tokens)[i] = token; /*set last token to null*/
	(void) argv;
}
