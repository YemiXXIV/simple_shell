#include "theshell.h"

/**
 * to_readinput - A function that reads input
 * @input: input to be read
 * @size: size of the input
 */

void to_readinput(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			to_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			to_print("Error while handling the file");
			exit(EXIT_SUCCESS);
		}
		input[strcspn(input, "\n")] = '\0';
	}
}
