#include "theshell.h"

/**
 * sh_strncpy - A function that copies a string
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of characcters to copy
 * Return: Pointer to the modified string
 */

char *sh_strncpy(char *dest, char *src, int n)
{
	int k, l;
	char *res = dest;
	k = 0;

	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}

	if (k < n)
	{
		l = k;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (result);
}


/**
 * sh_strncat -  A function thart concatenates two strings
 * @dest: The first srting
 * @src: The second string
 * @n: The max number of characters to concatenate
 * Return: Pointer to the concatenated string
 */

char *sh_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *result = dest;

	a = 0;

	while (dest[a] != '\0')
		a++;
	b = 0;

	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}

	if (b < n)
		dest[a] = '\0';
	return (result);
}

/**
 * sh_strchr - A function that locatesm acharacter in a string
 * @s: The string to search
 * @c: The character to be found
 * Return: Pointer to th first occurrence of c, or NULL if otherwise
 */

char *sh_strchr(char *s, char c)
{
	do{
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
