#include "shell.h"
/**
 *few - few function implementation for shell
 *@args: arguments passed
 *Return: Always 0
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
		if (WIFEXITED(status))
		{
			free(args);
			return (WEXITSTATUS(status));
		}
	}
	return (0);
}
/**
 *_printenv - print the enviroment
 *
 *Return: always 0
 */
int _printenv(void)
{
	unsigned int string = 0, environ_str = 0;

	for (; environ[string] != NULL; string++)
	{
		write(1, environ[environ_str], _strlen(environ[environ_str]));
		_putchar('\n');
		environ_str++;
	}
	return (0);
}
/**
 *_strtok - function for tokenization
 *@buffer: Pointer
 *Return: arrays of pointer
 */
char **_strtok(char *buffer)
{
	int i;
	char *token;
	char **buffer_keep;

	buffer_keep = calloc(1024, sizeof(char *));

	if (!buffer_keep)
		return (NULL);

	token = strtok(buffer, "\n\t :");

	i = 0;
	while (token != NULL)
	{
		buffer_keep[i] = token;
		token = strtok(NULL, ": \t\n");
		i++;
	}
	buffer_keep[i] = NULL;

	return (buffer_keep);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
