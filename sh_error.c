#include "theshell.h"

/**
 * sh_puts_err - A function that prints an input string
 * to the error stream.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void sh_puts_err(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		sh_put_err_char(str[i]);
		i++;
	}
}

/**
 * sh_put_err_char - A function that writes the character
 * to the error stream.
 * @c: The character to print.
 *
 * Return: On success, returns 1. On error, returns -1
 */

int sh_put_err_char(char c)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];

	if (c == EMPTY_BUFFER || i >= WRITE_BUFFER_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != EMPTY_BUFFER)
		buf[i++] = c;
	return (1);
}

/**
 * sh_putfs - A function that writes the character 
 * to the given file descriptor.
 * @c: The character to print.
 * @fs: The file descriptor to write to.
 *
 * Return: On success, returns 1. On error, returns -1
 */

int sh_putfs(char c, int fs)
{
	static int i;
	static char buf[WRITE_BUFFER_SIZE];

	if (c == EMPTY_BUFFER || i >= WRITE_BUFFER_SIZE)
	{
		write(fs, buf, i);
		i = 0;
	}
	if (c != EMPTY_BUFFER)
		buf[i++] = c;
	return (1);
}

/**
 * sh_putsfs - A function that prints an input string
 * to the specified file descriptor.
 * @str: The string to be printed.
 * @fs: The file descriptor to write to.
 *
 * Return: The number of characters put.
 */
int sh_putsfs(char *str, int fs)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += sh_putfs(*str++, fs);
	}
	return (i);
}
