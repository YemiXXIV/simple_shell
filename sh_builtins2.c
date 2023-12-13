#include "theshell.h"


/**
 * sh_display_history - A function that Displays the command
 * history, showing each command with its corresponding line number.
 * @p_info: Structure containing arguments.
 *
 * Return: Always 0
 */
int sh_dis_history(p_info_t *p_info)
{
	pr_list(p_info->history);
	return (0);
}

/**
 * sh_unset_alias - A function that removes an alias
 * from the alias list.
 * @p_info: Parameter structure.
 * @str: The string representing the alias.
 *
 * Return: 0 on success, 1 on error
 */
int sh_unset_alias(p_info_t *p_info, char *str)
{
	char *p;
	int r;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	r = delete_node_at_index(&(p_info->alias),
			get_node_index(p_info->alias, node_starts_with(p_info->alias, str, -1)));
	return (r);
}

/**
 * sh_set_alias - A function that sets an alias in the alias list.
 * @p_info: Parameter structure.
 * @str: The string representing the alias.
 *
 * Return: 0 on success, 1 on error
 */
int sh_set_alias(p_info_t *p_info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (sh_unset_alias(p_info, str));

	sh_unset_alias(p_info, str);
	return (add_node_end(&(p_info->alias), str, 0) == NULL);
}

/**
 * sh_print_alias - A function that prints an alias string.
 * @node: The alias node.
 *
 * Return: 0 on success, 1 on error
 */
int sh_print_alias(list_t *node)
{
	char *p = NULL, *b = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (b = node->str; b <= p; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * sh_alias - A function that mimics the behavior of
 * the alias builtin in a shell.
 * @p_info: Structure containing arguments.
 *
 * Return: Always 0
 */
int sh_alias(p_info_t *p_info)
{
	int i = (0);
	char *p = NULL;
	list_t *node = NULL;

	if (p_info->argc == 1)
	{
		node = p_info->alias;
		while (node)
		{
			sh_print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; p_info->argv[i]; i++)
	{
		p = _strchr(p_info->argv[i], '=');
		if (p)
			sh_set_alias(p_info, p_info->argv[i]);
		else
			sh_print_alias(node_starts_with(p_info->alias, p_info->argv[i], '='));
	}

	return (0);
}
