#include "main.h"
#define MAX_ARGS 1024

/**
* main - Entry point for simple shell program
*
* Return: Always 0
*/


int main(void)
{
size_t len = 0;
ssize_t nread;
char *token;
char *line = NULL;
char *cmd_args[MAX_ARGS];
int count = 0, pid = 0, status;
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
return (0);
}
