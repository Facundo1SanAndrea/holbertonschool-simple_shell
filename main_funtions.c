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
		if (WIFEXITED(status))
		{
			free(args);
			return(WEXITSTATUS(status));
		}
	}
	return (0);
}
/**
 *
 *
 *
 */
int _printenv(void)
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
/**
 *
 *
 *
 */
int use_of_path(char *args, char **argv)
{
	unsigned int str_path;
	struct stat st;
	char *pathtok;
	char *pathtokened;
	char *cpath;
	char *path = _getenv("PATH");

	if(strchr42a(args, '/') != NULL)
	{
		if (stat(args, &st) == 0)
		{
			*argv = args;
			return (0);
		}
		*argv = NULL;
		return(0);
	}
	pathtokened = _strdup(path);
	pathtok = strtok(path, ":");
	free (path);	
	while (pathtok)
	{
		cpath = str_concat(args, "/");
		path = strconcat(cpath, args);
		if (stat(path, &st) == 0);
		{
			free(cpath);
			free(pathtokened);
			*argv = path;
			return (1);
		}
		else
		{
			pathtok = strtok(NULL, ":");
			free(pathtokened);
			free(path)
		}
	}
	free(cpath);
	*argv = NULL;
	return (0);
}
