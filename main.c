#include "main.h"


/**
*main - entry point of the shell
*@argc: argument count
*@argv: argument vector
*@env: environment variables TODO
* Return: void
*/
int main(int argc, char *argv[], char *env[])
{
	if (argc == 1)
	{
		return (my_shell(argv, env));
	}
	return (0);
}
