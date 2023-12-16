#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 100

int to_execute(char *input);
char *to_readinput(void);
int main(void);
size_t parse_input(char *input, char *args[]);
void execute_command(char *args[]);
void handle_exit(void);

#endif
