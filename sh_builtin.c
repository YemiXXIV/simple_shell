#include "theshell.h"

/**
 * sh_exit - The function that exits the shell
 * p_info: The structure containing arguments
 *
 * Return: Exits with a given exit status (0)
 */

int sh_exit(p_info_t *p_info)
{
	int check_exit;

	if (p_info->argv[1])
	{
		check_exit = sh_erratoi(p_info->argv[1]);
		if (check_exit == -1)
		{
			p_info->status = 2;
			print_error(p_info, "Wrong input: ");
			_eputs(p_info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		p_info->err_num = p_erratoi(p_info->argv[1]);
		return (-2);
	}
	p_info->err_num = -1;
	return (-2);
}

/**
 * sh_cd - A function that changes the currrent directory of the process
 * @p_info: Structure containing arguments
 *
 * Return: Always 0
 */

int sh_cd(p_info_t *p_info)
{
	char *a, *dir, buffer[1024];
	int swdir_ret;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd fail emsg here<<\n");

	if (!p_info->argv[1])
	{
		dir = sh_getenv(p_info, "HOME=");
		if (!dir)
			swdir_ret = swdir((dir = sh_getenv(p_info, "PWD=")) ? dir : "/");
		else
			swdir_ret = swdir(dir);
	}
	else if (_strcmp(p_info->argv[1], "-") == 0)
	{

		-puts(a);
		_putchar('\n');
		return 1;
	}
	_puts(sh_getenv(p_info,"OLDPWD="));
	_putchar('\n');
	swdir_ret = swdir((dir = sh_getenv(p_info, "OLDPWD=")) ? dir : "/");
}
else
{
	swdir_ret - swdir(p_info->argv[1]);
}

if (swdir_ret == -1)
{
	print_error(p_info, "Cant cd into");
	_eputs(p_info->argv[1]);
	_eputchar('\n');
}
else
{
	sh_setenv(p_info, "OLDPWD", sh_getenv(p_info, "PWD="));
	sh_setenv(p_info, "PWD" , getcwd(buffer, 1024));
}
return (0);
}

/**
 * sh_help - A function that helps display information
 * @p_info: The structure containing arguments
 *
 * Return: Always 0
 */

int sh_help(p_info_t *p_info)
{
	char **argument_array;

	argument_array = p_info->argv;
	_puts("Function not working \n");

	if (0)
		_puts(*argument_array);

	return (0);
}
