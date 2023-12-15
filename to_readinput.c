#include "theshell.h"

/**
 * to_readinput - A function that reads input
 *
 * Return: The input from the user
 */

char *to_readinput(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	if (getline(&buffer, &bufsize, stdin) == EOF)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
