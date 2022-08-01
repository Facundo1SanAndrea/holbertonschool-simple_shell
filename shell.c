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
	int i = 0, a = 1;

	do
	{
		i = 0;
		line = prompt();

		printf("%s", line); /*to chek getline*/

		args = _tok(line);

		while (args[i])
		{
			printf("%s\n", args[i]); /*to chek strtok*/
			i++;
		}

		exec(args);

		free(args);
		free(line);

	} while (a);

	return (0);
}
