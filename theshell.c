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
		display_output();
		input = to_readinput();

		if (input != NULL)
		{
			if (to_execute(input) == -1)
				perror("Error");
			free(input);
		}
	}

	return (0);
}
