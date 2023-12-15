#include "theshell.h"

/**
 * main - The main function
 * Return: 0
 */

int main(void)
{
	char *input;
	size_t length;

	while (1)
	{
		display_output();
		input = to_readinput();
		length = strlen(input);

		if (length > 0 && input[length - 1] == '\n')
		{
			input[length - 1] = '\0';
		}
		to_execute(input);

		free(input);
	}

	return (0);
}
