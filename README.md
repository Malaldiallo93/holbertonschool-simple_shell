![](https://images.squarespace-cdn.com/content/v1/60bf70d860f31b4f60455443/5fbe5784-581c-4b7b-931f-8137e8f33476/Holberton+School.png)





# Simple Shell in C #

## Introduction ##

This project is a simple mini shell written in C that allows users to execute system commands such as cd, ls, pwd, etc.

## Compilation

To compile the code, use the following command:

```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

Here are the options used in the compilation command:

* -Wall: Enable all warnings.
* -Werror: Treat warnings as errors.
* -Wextra: Enable some extra warning flags that are not enabled by -Wall.
* -pedantic: Enforce strict ISO C standard compliance.
* -std=gnu89: Use the GNU89 dialect of the C language.
* *.c: Compile all C source files in the current directory.
* -o hsh: Specify the name of the output file as "hsh".

## Execution

To run the shell, execute the following command:

```
./hsh
```

## File List

`main.h`: Definition of all functions, constants, and structures used in the project.

`main.c`: Main file containing the main function and the implementation of the shell.

## How to Use the Shell

The shell waits for the user to enter a command, then reads and executes it using the `execvp` function. Built-in commands such as `cd`, `exit`, `env`, `setenv`, and `unsetenv` are also supported.

## Example Execution

```
$ ./hsh
$ ls
README.md hsh main.c main.h
$ cd ..
$ pwd
/home/user
$ exit
```
In this example, we executed the shell, then used the ls command to display the files in the current directory. Next, we used the cd command to go to the parent directory, then the pwd command to display the absolute path of the current directory. Finally, we exited the shell using the exit command.

## Known Limitations

The shell does not support redirections, pipes, and scripts.


# FLOWCHART

![Brainstorming-3](https://user-images.githubusercontent.com/124314236/234964025-4daef500-6d15-4a01-8384-112a49ca4898.jpg)
