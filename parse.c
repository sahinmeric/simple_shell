#include "main.h"

/** TODO
* parse - splitting
* @buffer: buffer
* @tokens: token
* @len: len of tokens
* Return: nothing
*/

void _parse(char **buffer, int *token_count, char ***tokens)
{
	char *token;
	int i;
	const char delim[] = " \t\n";

	*tokens = malloc(sizeof(char *) * (*token_count + 1));

	token = strtok(*buffer, delim);
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token; /* set tokens[i] to current token*/
		token = strtok(NULL, delim); /*set current token to next token*/
	}
	(*tokens)[i] = token; /*set last token to null*/
}
