#include "main.h"


/**
*main - entry point of the shell
*@argc: argument count
*@argv: argument vector
*
* Return: void
*/
int main(int argc, char **argv __attribute__((unused)))
{
	if (argc == 1)
	{
		my_shell();
	}
	return (0);
}
