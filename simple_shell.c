#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	size_t len = 0;
	ssize_t nread;
	char *line = NULL;
	char *token;
	char *cmd_args[MAX_ARGS];
	int count, pid, status;

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		count = 0;
		token = strtok(line, " \n");
		if (token == NULL)
			continue;
	while (token != NULL)
	{
		cmd_args[count] = token;
		count++;
		token = strtok(NULL, " \n");
	}
		cmd_args[count] = NULL;

	pid = fork();
		if (pid == 0)
		{
			exec_path(cmd_args);
			exit(127);
		}
		else
		{
			wait(&status);
			free(line);
			line = NULL;
			len = 0;
		}
	}

	free(line);
	return (0);
}
