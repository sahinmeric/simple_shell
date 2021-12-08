#include "main.h"

/**
 * tokenize - tokenize input
 * @buffer: buffer
 * @read_count: the number of characters read
 * Return: token count
 */
int tokenize(char **buffer, ssize_t read_count)
{
	const char delims[] = " \t\n";
	char *token;
	char *bff;
	int i = 0;

	bff = malloc(sizeof(char) * read_count + 1);
	if (bff == NULL)
	{
		perror("Error");
		return (0);
	}

	for (i = 0; buffer[0][i] != '\0'; i++) /*Copy buffer to bff*/
		bff[i] = buffer[0][i];
	bff[i] = buffer[0][i]; /*added null char at the end of bff*/

	token = strtok(bff, delims);
	for (i = 0; token != NULL; i++) /*count the tokens*/
		token = strtok(NULL, delims);

	free(bff);
	return (i); /*return token count*/
}

/**
 * _read - reads the input with getline
 * @buffer: buffer
 * @token_count: token count
 * Return: return 0 if success
 */
int _read(char **buffer, int *token_count)
{
	size_t bufsize = 0;
	ssize_t read_count;
	int i;
	char *bff;

	read_count = getline(buffer, &bufsize, stdin);

	if (read_count == -1)
	{
		free(*buffer);
		write(1, "\n", 1);
		exit(0);
	}

	bff = buffer[0];
	/*chk if the next char is a \n if there is a space*/
	for (i = 0; bff[i] == ' ' || bff[i] == '\t'; i++)
	{
		if (bff[i + 1] == '\n')
			return (1);
	}
	/*New line*/
	if (bff[0] == '\n')
	{
		return (1);
	}

	*token_count = tokenize(buffer, read_count);
	return (0);
}
