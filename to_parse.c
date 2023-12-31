#include "theshell.h"

/**
 * parse_input - A function that parses input into arguments.
 * @input: The input string to be parsed.
 * @args: An array to store the parsed arguments.
 *
 * Return: The number of arguments parsed.
 */

size_t parse_input(char *input, char *args[])
{
	size_t i = 0;

	args[i++] = strtok(input, " \t\n");
	while
		((args[i++] = strtok(NULL, " \t\n")) != NULL);

	return (i - 1);
}
