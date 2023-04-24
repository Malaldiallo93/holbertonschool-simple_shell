#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **get_path(char **envp);
void exec_path(char **cmd_args);
void exit_shell(char *line);
void env_shell(char **envp);

#endif /* MAIN_H */
