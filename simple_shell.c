/**
 * main - Entry point for the shell program
 *
 * This function implements a simple shell that allows the user to execute
 *
 * Return: Always 0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main(void)
{
char input[MAX_INPUT_SIZE];
char *command;

while (1)
{
printf("$ ");
fflush(stdout);
if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = 0;
if (strcmp(input, "cd") == 0)
{
chdir(getenv("HOME"));
continue;
}
command = strtok(input, " ");
if (command != NULL)
{
pid_t pid = fork();
if (pid == -1)
{
fprintf(stderr, "Error creating child process\n");
}
else if (pid == 0)
{
if (execlp(command, command, (char *) NULL) == -1)
{
fprintf(stderr, "Command not found\n");
exit(EXIT_FAILURE);
}
}
else
{
int status;
waitpid(pid, &status, 0);
}
}
}
return (0);
}
