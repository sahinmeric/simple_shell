#include "main.h"
/** TODO
* sighandler- handling signal
* @signum: signal
* Return: nothing
*/
void sighandler(int signum __attribute__((unused)))
{
	write(1, "\n$", 2);
}

/**TODO
*
*
*/
void _set(char **buffer, int *read_status, char ***tokens)
{
	*buffer = NULL; /* so getline func can automatically allocate the memory.*/
	read_status = 0;
	*tokens = NULL;
/*	printf("buffer and read_status set to 0");*/
}
/**TODO
*
*
*/
void _free(char **buffer, char ***tokens)
{
	free(*buffer);
	free(*tokens);
}

/**TODO
*
*
*/
int my_shell(char **argv, char **env)
{
	char *buffer; /*allocates a peace of memory in the heap & a memory address on the pointer*/
	int read_status = 0;
	int token_count;
	char **tokens;

/*	signal(SIGINT, sighandler); TODO it doesnt handle ctrl+D why?*/
	do {
	/*Set to 0 or NULL*/
	_set(&buffer, &read_status, &tokens);

	/*Interactive Shell prompt*/ /*TODO isatty will be added as a condition It tells whether the file descriptor is connected to a terminal or not.*/
	write(1, "$", 2);

	/*Read*/
	read_status = _read(&buffer, &token_count);/* figures the status of the read function & returns a values*/: 
	printf("read status is %d\n", read_status);
	/*if read status == 2 it means getline failed, free(buffer)*/
	if (read_status == 2) 
		free(buffer);
	/*Parse*/
	_parse(&buffer, &token_count, &tokens);

	/*TODO Check path with stat,return 0 if successful if not -1*/

	/*check and execute*/
	chk_cmd(&tokens, argv, env);
	/*Free*/
	_free(&buffer, &tokens);
	} while (1);
	return (0);
}
