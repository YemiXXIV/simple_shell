#include "theshell.h"

/**
 * main - The main function
 * Return: 0
 */

int main(void)
{
	char input_command[256];

	while (1)
	{
		display_output();
		to_execute(execute);
	}

	return (0);
}
