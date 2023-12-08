#include "theshell.h"

/**
 * to_print - A function that prints to the standard output
 * @prompt: prompt to be printed
 *
 * Return: returns nothing
 */

void to_print(const char *prompt)
{
	write(STDOUT_FILENO, &prompt, strlen(prompt));
}


