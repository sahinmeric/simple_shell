#include "main.h"

/**
* sighandler- handling ctrl + c signal, write \n instead of killing the process
* @signum: signal--
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
* @read_status: read status
* @token_count: token count
*/

void _set(char **buffer, char ***tokens, int *read_status, int *token_count)
{
	*buffer = NULL; /* so getline func can automatically allocate the memory.*/
	*tokens = NULL;
	*read_status = 0;
	*token_count = 0;
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
	char **tokens, **av;

	signal(SIGINT, sighandler);
	do {
	_set(&buffer, &tokens, &read_status, &token_count);

	/*Interactive Shell prompt*/
	if (isatty(STDIN_FILENO)) /*test if the fildes is connected to the terminal*/
		write(1, " $ ", 4);

	/*Read*/
	read_status = _read(&buffer);

	if (read_status == 1)
		continue;

	/*Parse*/
	_parse(&buffer, &token_count, &tokens, &av);

	/*Check and execute the command*/
	chk_cmd(&tokens, av, env, &buffer);

	/*Free*/
	_free(&buffer, &tokens);

	(void) argv;
	} while (1);

	return (0);
}
