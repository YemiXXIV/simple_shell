#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/** 
#define RD_BUFFER_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define EMPTY_BUFFER -1

#define INPUT_NORM  0
#define INPUT_OR    1
#define INPUT_AND   2
#define INPUT_CHAIN 3

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2

#define USE_GETLINE 0
#define USE_STRTOK  0

extern char **environ;


 * struct liststring - singly linked list
 * @num: Number
 * @str: The string
 * @next: Pointer to the next node
 *
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct parse_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *hist;
	list_t *alias;
	int env_changed;
	int status;
	char **environ;
	char **prompt_buf;
	int prompt_buf_type;
	int histcount;
	int pr_read;
} p_info_t;

typedef struct builtin
{
	char *type;
	int (*func)(p_info_t *);
} builtin_table;

#define INFO_INIT \
	{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}


int sh_is_interactive(p_info_t *p_info);
int sh_is_delimiter(char c, char *destr);
int sh_is_alpha(int c);
int sh_atoi(char *str);

int sh_exit(p_info_t *p_info);
int sh_cd(p_info_t *p_info);
int sh_help(p_info_t *p_info);

int sh_dis_env(p_info_t *p_info);
char *sh_get_env(p_info_t *p_info, const char *name);
int sh_set_env(p_info_t *p_info);
int sh_unset_env(p_info_t *p_info);
int sh_fill_env_list(p_info_t *p_info);

void sh_put_err(char *str);
int sh_put_err_char(char c);
int sh_putfs(char c, int fs);
int sh_putsfs(char *str, int fs);
int sh_erratoi(char *s);
void sh_pr_err(p_info_t *info, char *fstr);
int sh_pr_d(int input, int fd);
char *sh_convert_number(long int num, int base, int flags);
void sh_rem_comments(char *buf);

char *sh_strncpy(char *dest, char *src, int n);
char *sh_strncat(char *dest, char *src, int n);
char *sh_strchr(char *s, char c);

ssize_t sh_input_buf(p_info_t *p_info, char **buf, size_t *len);
ssize_t sh_get_input(p_info_t *p_info);
ssize_t sh_read_buf(p_info_t *p_info, char *buf, size_t *i);
int sh_get_line(p_info_t *p_info, char **ptr, size_t *len);
void sh_sigint_handler(__attribute__((unused))int sig_num);


int sh_setenv(p_info_t *p_info, char *var, char *value);
int sh_unsetenv(p_info_t *p_info, char *var); **/


void display_output(void);
void to_print(const char *prompt);
void to_execute(const char *input);
void to_readinput(char *input, size_t size);
int main(void);
/*int shFree(void **ptr);
char **shBreakString(char *str, char *delim);
char **shBreakString2(char *str, char delim);*/

#endif
