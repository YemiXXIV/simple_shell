#include "theshell.h"

/**
 * execute_command - A function that executes a command
 * in the child process.
 * @args: The array of command arguments.
 */

void execute_command(char *args[])
{
	if (execve(args[0], args, NULL) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
