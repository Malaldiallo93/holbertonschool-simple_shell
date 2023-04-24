#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 1024

char **get_path(char **envp);
void exec_path(char **cmd_args);
void exit_shell(char *line);
void env_shell(char **envp);

#endif /* SIMPLE_SHELL_H */
