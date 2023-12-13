#include "theshell.h"


/**
 * sh_input_buffer - A function that buffers chained commands
 * @p_info: structure
 * @buf: address of buffer
 * @len: address of len variable
 *
 * Return: bytes
 */

ssize_t sh_input_buffer(p_info_t *p_info, char **buf, size_t *len)
{
	ssize_t bytes_read = 0;
	size_t p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sh_sigint_handler);

#if USE_GETLINE
		bytes_read = getline(buf, &p, stdin);
#else
		bytes_read = sh_get_line(p_info, buf, &p);
#endif

		if (bytes_read > 0)
		{
			if ((*buf)[bytes_read - 1] == '\n')
			{
				(*buf)[bytes_read - 1] = '\0';
				bytes_read--;
			}

			p_info->linecount_flag = 1;
			sh_remove_comments(*buf);
			sh_build_history_list(p_info, *buf, p_info->histcount++);
			{
				*len = bytes_read;
				p_info->cmd_buf = buf;
			}
		}
	}
	return (bytes_read);
}

/**
 * sh_get_input - A function thst gets a line minus the newline
 * @p_info: structure containing shell information
 *
 * Return: bytes
 */
ssize_t sh_get_input(p_info_t *p_info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t bytes_read = 0;
	char **buf_p = &(p_info->arg);
	char *p;

	_putchar(EMPTY_BUFFER);
	bytes_read = sh_input_buffer(p_info, &buf, &len);

	if (bytes_read == -1)
		return (-1);

	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(p_info, buf, &j, i, len);

		while (j < len)
		{
			if (is_chain(p_info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			p_info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (sh_strlen(p));
	}

	*buf_p = buf;
	return (bytes_read);
}

/**
 * sh_read_buffer - A function that reads a buffer
 * @p_info: structure containing shell information
 * @buf: buffer
 * @i: size
 *
 * Return: bytes read
 */
ssize_t sh_read_buffer(p_info_t *p_info, char *buf, size_t *i)
{
	ssize_t bytes_read = 0;

	if (*i)
		return (0);

	bytes_read = read(p_info->pr_read, buf, RD_BUFFER_SIZE);

	if (bytes_read >= 0)
		*i = bytes_read;

	return (bytes_read);
}

/**
 * sh_get_line - A function that gets the next line
 * of input from STDIN
 * @p_info: structure
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: bytes
 */
int sh_get_line(p_info_t *p_info, char **ptr, size_t *length)
{
	static char buf[RD_BUFFER_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t bytes = 0, total_bytes = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		total_bytes = *length;

	if (i == len)
		i = len = 0;

	bytes = sh_read_buffer(p_info, buf, &len);

	if (bytes == -1 || (bytes == 0 && len == 0))
		return (-1);

	c = sh_strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = sh_realloc(p, total_bytes, total_bytes ? total_bytes + k : k + 1);

	if (!new_p)
		return (p ? (free(p), -1) : -1);

	if (total_bytes)
		sh_strncat(new_p, buf + i, k - i);
	else
		sh_strncpy(new_p, buf + i, k - i + 1);

	total_bytes += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = total_bytes;

	*ptr = p;
	return (total_bytes);
}

/**
 * sh_sigint_handler - A function that blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sh_sigint_handler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(EMPTY_BUFFER);
}
