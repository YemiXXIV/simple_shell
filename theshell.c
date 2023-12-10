#include "theshell.h"

/**
 * main - The main function
 * Return: 0
 */

int main(void)
{
	char input[256];

	while (1)
	{
		display_output();
		to_execute(input);
		to_readinput(input, sizeof(input));
	}

	return (0);
}
