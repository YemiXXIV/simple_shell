#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void display_output(void);
void to_print(const char *prompt);
void to_execute(const char *input);
void to_readinput(char *input, size_t size);
int main(void);

#endif
