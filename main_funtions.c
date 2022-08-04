#include "shell.h"
/**
 *
 *
 */
int few(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
		}
		free(args);
	}
	else
	{
		wait(&status);
		free(args);
	}
	return (0);
}
/**
 *
 *
 *
 */
int _getenv(void)
{
	unsigned int string = 0, environ_str = 0;

	for (;environ[string] != NULL; string++)
	{
		write(1, environ[environ_str], _strlen(environ[environ_str]));
		_putchar('\n');
		environ_str++;
	}
	return (0);
}
/**
 *
 *
 */
char **_strtok(char *buffer)
{
	int i;
	char *token;	
	char **buffer_keep;


	buffer_keep = calloc(1024, sizeof(char *));

	if (!buffer_keep)
		return (NULL);

	token = strtok(buffer, "\n\t ");

	i = 0;
	while (token != NULL)
	{
		buffer_keep[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	buffer_keep[i] = NULL;

	return (buffer_keep);
}
/**
 *
 *
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
