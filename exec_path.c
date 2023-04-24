#include "main.h"

/**
 * exec_path - Execute a command from the PATH directories
 * @cmd_args: Pointer to an array of strings
 * containing the command and its arguments
 */
void exec_path(char **cmd_args)
{
	int i;
	char **path, *cmd_path;
	extern char **environ;

	path = get_path(environ);
	for (i = 0; path[i] != NULL; i++)
	{
		cmd_path = malloc(sizeof(char) * MAX_ARGS);
	if (cmd_path == NULL)
	{
		perror("malloc");
		exit(1);
	}
	strcpy(cmd_path, path[i]);
	strcat(cmd_path, "/");
	strcat(cmd_path, cmd_args[0]);
	if (access(cmd_path, F_OK) == 0)
	{
		execve(cmd_path, cmd_args, environ);
		perror("exeve");
	}
	free(cmd_path);
	}
	free(path);
}
