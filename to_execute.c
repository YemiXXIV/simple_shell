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
	char *args[MAX_INPUT_LENGTH];

	char *input_copy = strdup(input);

	if (input_copy == NULL)
	{
		perror("Error");
		return (-1);
	}

	parse_input(input, args);

	if (strcmp(args[0], "exit") == 0)
	{
		free(input_copy);
		handle_exit();
	}

	pid = fork();

	if (pid == 0)
	{
		execute_command(args);
	}
	else if (pid < 0)
	{
		perror("Error");
		free(input_copy);
		return (-1);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}

	free(input_copy);
	return (0);
}
