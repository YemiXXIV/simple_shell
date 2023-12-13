#include "theshell.h"

/**
 * sh_get_environ - A function that returns the string
 * copy of the environment
 * @p_info: Structure containing arguments.
 * Return: Always 0
 */

char **sh_get_environ(p_info_t *p_info)
{
	if (!p_info->environ || p_info->env_changed)
	{
		p_info->environ = list_to_strings(p_info->env);
		p_info->env_changed = 0;
	}

	return (p_info->environ);
}

/**
 * sh_unset_env - A function that removes an environment variable
 * @p_info: Structure containing arguments.
 * @var: the string env var property
 * Return: 1 on delete, 0 if otherwise
 */

int sh_unset_env(p_info_t *p_info, char *var)
{
	list_t *node = p_info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			p_info->env_changed = delete_node_at_index(&(p_info->env), i);
			i = 0;
			node = p_info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (p_info->env_changed);
}

/**
 * sh_set_env - A function that initialize a new
 * environment variable
 * @p_info: Structure containing arguments.
 * @var: the string env var property
 * @value: the string env value
 * Return: Always 0
 */
int sh_set_env(p_info_t *p_info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = p_info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			p_info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(p_info->env), buf, 0);
	free(buf);
	p_info->env_changed = 1;
	return (0);
}
