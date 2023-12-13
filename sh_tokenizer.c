#include "theshell.h"

/**
 * shBreakString - Breaks a string into words, ignoring
 * repeated delimiters
 * @str: The input string
 * @delim: The delimiter string
 * Return: Pointer to an array of strings, or NULL if otherwise
 */

char **shBreakString(char *str, char *delim)
{
	int a, b, c, d, numInputs = 0;
	char **input;

	if (str == NULL || str[0] == 0)
		return (NULL);

	if (!delim)
		delim = " ";

	for (a = 0; str[a] != '\0'; a++)
		if (!shIsDelimiter(str[a], delim) &&
		(shIsDelimiter(str[a + 1], delim) || !str[a + 1]))
			numInputs++;

	if (numInputs == 0)
		return (NULL);

	input = malloc((1 + numInputs) * sizeof(char *));
	if (!input)
		return (NULL);

	for (a = 0, b = 0; b < numInputs; b++)
	{
		while (shIsDelimiter(str[a], delimit))
			a++;

		c = 0;
		while (!shIsDelimiter(str[a + c], delim) && str[a + c])
			c++;

		inputs[b] = malloc((c + 1) * sizeof(char));
		if (!inputs[b])
		{
			for (c = 0; c < b; c++)
				free(inputs[c]);
			free(inputs);
			return (NULL);
		}

		for (d = 0; d < c; d++)
			inputs[b][d] = str[a++];
		inputs[b][d] = 0;
	}
	inputs[b] = NULL;
	return (inputs);
}

/**
 * shBreakString2 - A function that breaks a string into words
 * @str: the input string
 * @delim: the delimiter
 * Return:Pointer to an array of strings, or NULL if otherwise
 */
char **shBreakString2(char *str, char delim)
{
	int i, j, k, l, numinputs = 0;
	char **inputs;

	if (str == NULL || str[0] == 0)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delim && str[i + 1] == delim) ||
			(str[i] != delim && !str[i + 1]) || str[i + 1] == delim)
				numinputs++;

	if (numinputs == 0)
		return (NULL);

	inputs = malloc((1 + numinputs) * sizeof(char *));
	if (!inputs)
		return (NULL);

	for (i = 0, j = 0; j < numinputs; j++)
	{
		while (str[i] == delim && str[i] != delim)
			i++;

		k = 0;
		while (str[i + k] != delim && str[i + k] && str[i + k] != delim)
			k++;

		inputs[j] = malloc((k + 1) * sizeof(char));
		if (!inputs[j])
		{
			for (k = 0; k < j; k++)
				free(inputs[k]);
			free(inputs);
			return (NULL);
		}

		for (l = 0; l < k; l++)
			inputs[j][l] = str[i++];
		inputs[j][l] = 0;
	}
	inputs[j] = (NULL);
	return (inputs);
}
