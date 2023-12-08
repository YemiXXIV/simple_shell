#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void display_output(void);
void to_print(const char *prompt);
void to_execute(const char *execute);
int main(void);

#endif
