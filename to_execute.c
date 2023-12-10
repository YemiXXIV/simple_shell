#include "theshell.h"

/**
 * to_execute - A function that executes a child process
 * @input: The command to be executed
 *
 */

void to_execute(const char *input)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		write(2, "Error in forking process.\n",
		      strlen("Error in forking process.\n"));
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execlp("/bin/sh", "/bin/sh", "-c", input, NULL) == -1)
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
