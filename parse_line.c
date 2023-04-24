#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 1024

/**
 * parse_line - tokenize a string into arguments
 *
 * @line: the string to tokenize
 * @argv: an array of pointers to store the arguments in
 *
 * Return: the number of arguments parsed
 */

int parse_line(char *line, char **argv)
{
int count = 0;
char *token;

token = strtok(line, " \n");
while (token != NULL && count < MAX_ARGS - 1)
{
argv[count] = token;
count++;
token = strtok(NULL, " \n");
}
argv[count] = NULL;
return (count);
}
