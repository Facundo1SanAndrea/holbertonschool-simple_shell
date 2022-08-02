#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
	char *buffer = NULL;
	int keepgetline, status;
	char **buff_token;
	size_t bufsize = 0;

	while (true)
	{
		write(1, "#cisfun$ ", 8);

		keepgetline = getline(&buffer, &bufsize, stdin);
		
		if (keepgetline == -1)
			break;
		if (keepgetline == '\n')
			continue;
		
		buff_token = _strtok(buffer);

		if (buff_token[0] == "exit")
		{
			free(buff_token);
			free(buffer);
			exit(0);
		}
		if (buff_token[0] == "env")
		{
			_getenv();
		}
		
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
		}
		if (pid == 0)
		{
			execve(buff_token[0], buff_token, NULL);
			free(buff_token);
		}
		else
			wait(&status);
			free(buff_token);
	}
	return (0);
}
