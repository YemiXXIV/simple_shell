#include "theshell.h"

/**
 * to_execute - A function that executes a child process
 * @input: The command to be executed
 *
 * Return: 0 on success, -1 if otherwise
 */

int to_execute(char *input)
{
	pid_t pid;
	int status;

	char *args[2];

	args[0] = input;
	args[1] = NULL;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		_exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
	{
		perror("Error");
		return (-1);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}

	return (0);

}
