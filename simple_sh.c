#include "main.h"
/**
* sighandler- skkiped the ctrl signal
* @signum: signal
* Return: nothing
*/
void sighandler(int signum __attribute__((unused)))
{
	write(1, "\n$", 5);
}

/**
* my_shell - execute a simple shell
* Return: nothing
*/

int my_shell(char **argv, char **env)
{
	char *buffer;
	size_t bufsize = 32;

	char **pbuffer = &buffer;
	size_t *pbufsize = &bufsize;
	size_t input_len;
	char *token;

	buffer = malloc(bufsize * sizeof(char));
/*	signal(SIGINT, sighandler); TODO it doesnt handle ctrl+D why?*/
	do {
	/*Interactive Shell prompt*/
	write(1, "$", 1);

	/*Read*/
	input_len = getline(pbuffer, pbufsize, stdin);

	/*Tokenize */
	token = strtok(buffer, "\n");

	/*TODO Check path with stat,return 0 if successful if not -1*/

	/*Execute*/
	execute(token, argv, env);

	} while (1);
	return (0);
}
