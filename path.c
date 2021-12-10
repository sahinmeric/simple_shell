#include "main.h"

/**
 *_strlen - gets the length of a string
 *@st: string that will be input to the function
 *Return: the length of @st
 */
int _strlen(char *st)
{
	int i = 0;

	for (i = 0; st[i] != '\0'; i++)
	;
	return (i);
}

/**
 * create_path_list - creating singly linked list from path
 * @path: path env value
 * @head: head of list
 * Return: head pointer
 */
path_node *create_path_list(char *path, path_node **head)
{
	int len;
	path_node *new;
	char *s = _strdup(path);

	if (s == NULL)
		return (NULL);

	for (len = 0; s[len]; len++)
	;

	new = malloc(sizeof(path_node));

	if (new == NULL)
	return (NULL);
	else
	{
		new->path = s;
		new->next = *head;
	}

	*head = new;

	return (new);
}

/**
 * add_path - append path to the command
 * @tokens: token pointer
 * @env: pointer to env variables
 * Return: return 0 if success
 */
int add_path(char ***tokens, char **env)
{
	char *env_path, *tkn, *new_cmd = NULL;
	int len_dir, len_cmd;
	struct stat st;
	path_node *path_n, *copy_list;

	st.st_mode = 0;

	env_path = _strdup(_getenv("PATH", env));
	tkn = strtok(env_path, ":");
	while (tkn != NULL)
	{
		create_path_list(tkn, &path_n);
		tkn = strtok(NULL, ":");
	}
	copy_list = path_n;
	len_cmd = _strlen((*tokens)[0]);
	while (path_n != NULL)
	{
		len_dir = _strlen(path_n->path);
		new_cmd = malloc(sizeof(char) * (len_dir + len_cmd + 2));
		new_cmd[0] = '\0';
		_strcat(new_cmd, path_n->path);
		_strcat(new_cmd, "/");
		_strcat(new_cmd, (*tokens)[0]);

		stat(new_cmd, &st);
		if ((access(new_cmd, F_OK | X_OK) == 0) &&
				((st.st_mode & S_IFMT) == S_IFREG))
		{
			(*tokens)[0] = new_cmd;
			return (0);
		}
		else /*This part is broken*/
			perror("Error: ");
		free(new_cmd);
		new_cmd = NULL;
		path_n = path_n->next;
	}
	free_list(copy_list);
	return (0);
}

/**
* free_list- frees the linked list containing the path directories
* @head: the linked list to be freed
* Return: nothing
*/
void free_list(path_node *head)
{
	path_node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->path);
		free(temp);
	}
}
