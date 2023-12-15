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

	char **args = malloc(2 * sizeof(char *));

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
	}
	else if (pid < 0)
	{
		perror("Error");
		free(args);
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(args);
	return (0);
}
