#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_ARGS 1024

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
char *line;
char *argv[MAX_ARGS];
int status, count, pid;

while (1)
{
printf("$ ");
line = read_line();
if (line == NULL)
break;
count = parse_line(line, argv);
if (count == 0)
continue;
pid = fork();
if (pid == -1)
{
perror("Erreur : échec de fork()\n");
exit(EXIT_FAILURE);
}
if (pid == 0)
{
execvp(argv[0], argv);
perror("Erreur : commande introuvable\n");
exit(EXIT_FAILURE);
}
else
{
wait(&status);
}
}

free(line);
return (0);
}
