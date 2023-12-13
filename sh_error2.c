#include "theshell.h"


/**
 * sh_erratoi - A function that converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: 0 if no numbers in the string, -1 if oterwise
 */

int sh_erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * sh_pr_err - A function that prints an error message.
 * @info: The parameter return information struct.
 * @fstr: String containing the specified error type.
 *
 * Return: Nothing.
 */
void sh_pr_err(p_info_t *info, char *fstr)
{
	sh_put_err(info->fname);
	sh_put_err(": ");
	sh_pr_d(info->line_count, STDERR_FILENO);
	sh_put_err(": ");
	sh_put_err(info->argv[0]);
	sh_put_err(": ");
	sh_put_err(fstr);
}

/**
 * sh_pr_d - Prints a decimal (integer) number (base 10).
 * @input: The input number.
 * @fd: The file descriptor to write to.
 *
 * Return: Number of characters printed.
 */
int sh_print_d(int input, int fd)
{
	int (*__putchar)(char) = sh_putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = sh_eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * sh_convert_number - A function that Converts a function, to a clone of itoa.
 * @num: The number to convert.
 * @base: The base for conversion.
 * @flags: Argument flags.
 *
 * Return: The converted string.
 */
char *sh_convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * sh_rem_comments - A function that replaces the first instance
 * of '#' with '\0'.
 * @buf: The address of the string to modify.
 *
 * Return: Always 0.
 */
void sh_rem_comments(char *buf)
{
	int a;

	for (a = 0; buf[a] != '\0'; a++)
		if (buf[a] == '#' && (!i || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
}
