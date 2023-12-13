#include "theshell.h"

/**
 * sh_is_interactive - A function that returns true if the shell is in interactive mode
 * @p_info: The struct address
 *
 * Return: 1 if in interactive mode, 0 if otherwise
 */

int sh_is_interactive(p_info_t *p_info)
{
	return (isatty(STDIN_FILENO) && p_info->pr_read <= 2);
}

/**
 * sh_is_delimiter - A function that checks if
 * character is a delimiter
 * @c: The character to check
 * @destr: The delimiter string
 * Return: 1 if true, 0 if false
 */

int sh_is_delimiter(char c, char *destr)
{
	while (*destr)
		if (*destr++ == c)
			return (1);
	return (0);
}

/**
 * sh_is_alpha - A function that checks for the alphabetic character
 * @c: The character to be inputted
 * Return: 1 if alphabetic, 0 if otherwise
 */

int sh_is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z'));
}

/**
 * sh_atoi - A function that converts a string to an integer
 * @str: The string to be converted
 * Return: Converted number if true, 0 if string has no numbers
 */

int sh_atoi(char *str)
{
	int i, sh_sign = 1, sh_flag = 0, sh_output;
	unsigned int sh_result = 0;

	for (i = 0; str[i] != '\0' && sh_flag != 2; i++)
	{
		if (str[i] == '-')
			sh_sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			sh_flag = 1;
			sh_result *= 10;
			sh_result += (str[i] - '0');
		}
		else if (sh_flag == 1)
			sh_flag = 2;
	}

	sh_output = (sh_sign == -1) ? -sh_result : sh_result;

	return sh_output;
}


