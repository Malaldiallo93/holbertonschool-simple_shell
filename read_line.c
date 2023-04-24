#include <stdio.h>
#include <stdlib.h>

/**
 * read_line - reads a line of input from stdin
 *
 * Return: a pointer to the input line, or NULL if no input was available
 */

char *read_line(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

nread = getline(&line, &len, stdin);
if (nread == -1)
{
free(line);
return (NULL);
}
return (line);
}
