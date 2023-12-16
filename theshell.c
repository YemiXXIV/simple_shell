#include "theshell.h"

/**
 * main - The main function
 * Return: 0
 */

int main(void)
{
	char *input;

	while (1)
	{
		input = to_readinput();

		if (input != NULL)
		{
			to_execute(input);
			free(input);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}
