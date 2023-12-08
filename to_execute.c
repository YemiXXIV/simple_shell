#include "theshell.h"

/**
 * to_execute - A function that executes a child process
 * @execute: The command to be executed
 *
 */

void to_execute(const char *execute)
{
	pid_t sibling_pid = fork();

	if (sibling_pid == -1)
	{
		write(2, "Error in forking process.\n",
		      strlen("Error in forking process.\n"));
		exit(EXIT_FAILURE);
	}
	else if (sibling_pid == 0)
	{
		if (execlp("/bin/sh", "/bin/sh", "-c", execute, NULL) == -1)
		{
			write(2, "Error in executing the command.\n",
			      strlen("Error in executing the command.\n"));
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
