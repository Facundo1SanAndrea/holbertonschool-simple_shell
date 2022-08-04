#include "shell.h"
/**
 *
 *
 *
 */
int main(void)
{
	char *buffer = NULL, **buff_token;
	int keepgetline;
	size_t bufsize = 0;
	int value_of_retu = 0, path = 0;

	while (1)
	{
		my_prompt();
		signal(SIGINT, ctrl_d);
		keepgetline = getline(&buffer, &bufsize, stdin);
		if (keepgetline == EOF)
			break;
		if (buffer[0] == '\n')
			continue;
		buff_token = _strtok(buffer);
		if (buff_token[0] == NULL)
		{
			free (buff_token);
			break;
		}
		if (_strcmp(buff_token[0], "exit") == 0)
		{
			free (buff_token);
			free (buffer);
			return(value_of_retu);
		}
		if (_strcmp(buff_token[0] , "env") == 0)
		{
			_printenv();
			if(buff_token)
				free(buff_token);
			continue;
		}
		value_of_retu = few(buff_token);
	}
	free (buffer);
	return (value_of_retu);
}
/**
 *
 *
 *
 */


int my_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(1, "#cisfun$ ", 9);
	return (0);
}
/**
 *
 *
 *
 */
void ctrl_d(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 2);
		my_prompt();
	}
}
