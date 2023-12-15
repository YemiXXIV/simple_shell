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
	size_t length = strlen(buffer);

	if (getline(&buffer, &bufsize, stdin) == EOF)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	if (length > 0 && buffer[length - 1] == '\n')
	{
		buffer[length - 1] = '\0';
	}

	return (buffer);
}
