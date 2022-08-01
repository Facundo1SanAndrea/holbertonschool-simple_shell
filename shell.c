#include "shell.h"

/**
 *main - main body function of the shell
 *only call system
 *Return: zero
 *
 */

int main(void)
{
	char *line;
	char **args;

	do
	{
	line = prompt();

	agrs = tok(line);

	exec(args);

	free(args);
	free(line);

	}
	while (1);
}
