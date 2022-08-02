#include "shell.h"
/**
 *
 *
 *
 */
int _getline()
{
	char *buffer;
	size_t bufsize = 32;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("ERROR");
		exit (1);
	}
	getline(&buffer, &bufsize, stdin);
	free (buffer);
	return (0);
}
/**
 *
 *
 *
 */
int _strtok()
{
	char *buffer, *buff_cpy, *buff_token;
	size_t bufsize = 32;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Error");
		return (-1);
	}
	_getline(&buffer, &bufsize, stdin);;
	
	buff_cpy = malloc(bufsize * sizeof(char));
	if (buff_cpy == NULL)
	{
		perror("Error");
		free(buffer);
		return (-1);
	}
	_strcyp(buff_cpy, buffer);
	buff_token = strtok(buff_cpy, " ");
	while (buff_token != NULL)
	{
		buff_token = strtok(NULL, " ");
	}
	free(buff_cpy);
	free(buffer);
	return (0);
}
/**
 *
 *
 */
int fwe(char **args)
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
	}
	else
		wait(&status);

	return (0);
}
/**
 *
 *
 *
 */
char *_getenv(const char *name)
{
	int elem, index;
	bool are_equal;

	for (elem = 0; environ[elem] != NULL; elem++)
	{
		are_equal = true;
		for (index = 0; environ[elem][index])
		{
			are_equal = false;
			break;
		}
	}
	if (are_equal)
	{
		return (&environ[elem][index + 1]);
	}
	return (NULL);
}

/**
 *
 *
 *
 *
 */

