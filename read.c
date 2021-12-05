#include "main.h"
/**
 *TODO
 *
 *
 */
int tokenize(char **buffer, ssize_t read)
{
	const char delims[] = " \t\n";
	char *token;
	char *bff;
	int i = 0;

	bff = malloc(sizeof(char) * read + 1);
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
	printf("token_count is %d\n", i);
	return (i); /*return token count*/
}

/*
 *TODO
 *
 *
 *
 *
 */
int _read(char **buffer, int *token_count)
{
	size_t bufsize = 0;
	ssize_t read;
	int i;
	char *bff;

	read = getline(buffer, &bufsize, stdin);
	if (read == -1) /*if getline fails*/
		return (2);

	bff = buffer[0];
	for (i = 0; bff[i] == ' ' || bff[i] == '\t'; i++) /*check if the next char is a \n till you find space or tab and return (1) */
	{
		if (bff[i + 1] == '\n')
			return (1);
	}
	/*new line*/
	if (bff[0] == '\n')
		return (1);

	*token_count = tokenize(buffer, read);
	return (0);
}
