#include "shell.h"
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

