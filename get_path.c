#include "main.h"

/**
 * get_path - Get the PATH environment variable
 * @envp: Pointer to the environment variables
 * Return: Pointer to an array of strings containing the PATH directories
 */
char **get_path(char **envp)
{
	int i;
	char **path, *temp;

	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		break;
		i++;
	}
		temp = strtok(envp[i], "=");
		temp = strtok(NULL, "=");

	path = malloc(sizeof(char *) * MAX_ARGS);
	if (path == NULL)
	{
		perror("malloc");
		exit(1);
	}
	i = 0;
	temp = strtok(temp, ":");
	while (temp != NULL)
	{
		path[i] = temp;
		temp = strtok(NULL, ":");
		i++;
	}
	path[i] = NULL;

	return (path);
}
