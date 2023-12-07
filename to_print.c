#include "theshell.h"

void to_print(const char *prompt)
{
	write(STDOUT_FILENO, prompt, strlen(prompt));
}


