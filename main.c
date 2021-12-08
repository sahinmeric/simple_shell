#include "main.h"

/**
* main - entry point of the shell
* @argc: argument count
* @argv: argument vector
* @env: environment variables
* Return: 0 on success, non-zero value on fail.
*/

int main(int argc, char *argv[], char *env[])
{
	if (argc == 1) /*Our program doesn't accept more than 1 argument*/
	{
		return (my_shell(argv, env));
	}
	return (0);
}
