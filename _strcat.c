#include "main.h"

/**
* _strcat - concats two strings. 
* @dest: the variable to be joined with src
* @src: the variable to be joined with dest
* Return: a pointer to new dest
*/

char *_strcat(char *dest, char *src)
{
	int n, l;

	n = 0;

	while (dest[n])
		n++;

	for (l = 0; src[l] != '\0'; l++)
	{
		dest[n] = src[l];
		n++;
	}

		return (dest);
}
