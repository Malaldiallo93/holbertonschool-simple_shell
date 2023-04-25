#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 1024

typedef struct built_in {
    char name;
    int (func)(char args);
} built_in;

int execute(char args, char envp);
int execute_built_in(char args);
int launch_process(char args, char envp);
int shell_exit(char args);
int shell_env(char args);

#endif /* SIMPLE_SHELL_H */
