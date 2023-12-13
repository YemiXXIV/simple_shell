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
		to_readinput(input, sizeof(input));
		to_execute(input);
	}

	return (0);
}
