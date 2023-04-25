#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define MAX_ARGS 100 


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

	if (strcmp(cmd_args[0], "exit") == 0)
		break;
	else if (strcmp(cmd_args[0], "env") == 0)
	{
		char **env = __environ;
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		continue; 
	}

	pid = fork();
	if (pid == 0)
	{
		execvp(cmd_args[0], cmd_args);
		fprintf(stderr, "Error: command not found\n");
		exit(1);
	}
	else
	{
		wait(&status);
	}

	}

	free(line);
	return 0;
}
