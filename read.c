#include "main.h"

/**
 * _read - reads the input with getline
 * @buffer: pointer to *buffer
 * Return: return 0 if success
 */
int _read(char **buffer)
{
	size_t bufsize = 0;
	ssize_t read_count;

	read_count = getline(buffer, &bufsize, stdin);

	if (read_count == -1)
	{
		write(1, "\n", 1);
		exit(0);
	}
	/*New line*/
	if (*buffer[0] == '\n')
	{
		return (1);
	}
	return (0);
}
