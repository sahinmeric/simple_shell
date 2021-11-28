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

int my_shell(void)
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = malloc(bufsize * sizeof(char));

/*	signal(SIGINT, sighandler); */
	do {
	printf("$");
	characters = getline(&buffer, &bufsize, stdin);

	printf("%lu characters were read.\n", characters);
	printf("you typed: %s\n", buffer);
	} while (1);
	return (0);
}
