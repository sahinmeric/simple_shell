#include "main.h"

/**
* _strcat - concats two strings.
* @dest: destination char pointer
* @src: source char pointer
* Return: a char pointer to destination
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
