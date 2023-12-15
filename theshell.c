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
		to_execute(input);

		free(input);
	}

	return (0);
}
