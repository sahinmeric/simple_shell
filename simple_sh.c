#include "main.h"

/**
* sighandler- handling ctrl + c signal, write \n instead of killing the process
* @signum: signal
* Return: nothing
*/
void sighandler(int signum __attribute__((unused)))
{
	write(1, "\n$", 2);
}

/**
* _set - sets some start values to NULL
* @buffer: buffer
* @tokens: tokens
*/

void _set(char **buffer, char ***tokens)
{
	*buffer = NULL; /* so getline func can automatically allocate the memory.*/
	*tokens = NULL;
}

/**
* _free - deallocates allocated memories of passed args.
* @buffer: buffer
* @tokens: tokens
*/
void _free(char **buffer, char ***tokens)
{
	free(*buffer);
	free(*tokens);
}

/**
* my_shell - execute a simple shell
* @argv: argument vectors
* @env: environment vectors
* Return: nothing
*/
int my_shell(char **argv, char **env)
{
	char *buffer;
	int read_status = 0;
	int token_count;
	char **tokens;

	signal(SIGINT, sighandler);
	do {
	_set(&buffer, &tokens);

	/*Interactive Shell prompt*/
	if (isatty(STDIN_FILENO)) /*test if the fildes is connected to the terminal*/
		write(1, "$", 2);

	/*Read*/
	read_status = _read(&buffer, &token_count);

	if (read_status == 1)
		continue;

	if (read_status == 2)
		printf("read_status is %d\n", read_status);
	/*Parse*/
	_parse(&buffer, &token_count, &tokens);

	/*Check and execute the command*/
	chk_cmd(&tokens, argv, env);

	/*Free*/
	_free(&buffer, &tokens);

	} while (1);
	return (0);
}
