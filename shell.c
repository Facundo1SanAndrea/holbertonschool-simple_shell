#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
	char *buffer = NULL;
	int keepgetline;
	char **buff_token;
	size_t bufsize = 0;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		keepgetline = getline(&buffer, &bufsize, stdin);
		
		if (keepgetline == -1)
			break;
		if (buffer[0] == '\n')
			continue;
		
		buff_token = _strtok(buffer);
		if (!_strcmp(buff_token[0] ,"exit"))
		{
			free (buff_token);
			free (buffer);
			exit(0);
		}
		if (_strcmp(buff_token[0] , "env") == 0)
			_getenv();

		few(buff_token);
	}
	return (0);
}
