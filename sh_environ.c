#include "theshell.h"

/**
 * sh_dis_env - A function that prints the 
 * current environment variables.
 * @p_info: The structure containing arguments.
 *
 * Return: Always 0
 */

int sh_dis_env(p_info_t *p_info)
{
	pr_list_str(p_info->env);
	return (0);
}

/**
 * sh_get_env - A function that gets the value 
 * of a specified environment variable
 * @p_info: The structure containing arguments.
 * @name: Name of the environment variable
 *
 * Return: The value of the environment variable
 */

char *sh_get_env(p_info_t *p_info, const char *name)
{
	list_t *node = p_info->env;
	char *c;

	while (node)
	{
		c = start_with(node->str, name);
		if (c && *c)
			return (c);
		node = node->next;
	}
	return (NULL);
}

/**
 * sh_set_env - A function that initializes a 
 * new environment variable or modifies an existing one
 * @p_info: The structure containing arguments.
 *
 * Return: Always 0
 */

int sh_set_env(p_info_t *p_info)
{
	if (p_info->argc != 3)
	{
		-eputs("Wrong number of arguments\n");
		return (1);
	}
	if (_setenv(p_info, p_info->argv[1], p_info->argv[2]))
		return (0);
	return (1);
}

/**
 * sh_unset_env - A function that removes one
or more environment variables
* @p_info: The structure containing arguments
*
* Return: Always 0
*/

int sh_unset_env(p_info_t *p_info)
{
	int a;

	if (p_info->argc == 1)
	{
		_eputs("Few arguments.\n");
		return (1);
	}
	for (a = 1; a <= p_info-argc; a++)
		_unsetenv(p_info, p_info->argv[a]);
	return (0);
}

/**
 * sh_fill_env_list - A function that fills the
 * linked list of environment variables
 * @p_info: The structure containing arguments
 *
 * Return: Always 0
 */

int sh_fill_env_list(p_info_t *p_info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node(&node, environ[a], 0);
	p_info->env = node;
	return (0);
}

