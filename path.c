#include "main.h"
/**
 *
 *
 *
 */
path_node *create_path_list(char *path, path_node **head)
{
	char *s = strdup(path);
	path_node *new_node, *aux;

	new_node = malloc(sizeof(path_node));

	new_node->path = s;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	aux = *head;
	while (aux->next)
	{
		aux = aux->next;
	}
	aux->next = new_node;

	printf("new node -> str is %s\n", new_node->path);
	return (*head);
}





/**
 *
 *
 *
 */
int add_path(char ***tokens, char **env)
{
	char *env_path;
	char *tkn;
	int i;
	char *new_cmd;
	struct stat st;

	path_node *path_n = NULL;

	env_path = getenv("PATH");

	tkn = strtok(env_path, ":");
	for (i = 0; tkn != NULL; i++)
	{
		create_path_list(tkn, &path_n);
		tkn = strtok(NULL, ":");
	}

	while (path_n)
	{
		/*add path to cmd*/
		new_cmd = _strcat(path_n->path, "/");
		new_cmd = _strcat(new_cmd, **tokens);
		printf("new cmd is %s\n", new_cmd);
		path_n = path_n->next;

		/*check with stat if path + first_token exist*/
		stat(new_cmd, &st);
		if ((st.st_mode & S_IFMT) == S_IFREG) /*exists*/
		{
			**tokens = new_cmd;
			return (0);
			printf("path exist\n");
		}
		else
		{
			printf("path doesnt exist\n");
		}
	}
	/*if exists, first_token = path + cmd */

	/*if doesn't exist command not found */

	return (0);
}
