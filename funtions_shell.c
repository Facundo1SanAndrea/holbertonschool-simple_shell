#include "shell.h"

/**
 *
 */
char *prompt(void)
{
	size_t bufsize = 32;
	char *buffer;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		exit (1);

	printf("#cisfun$ ");
	getline(&buffer, &bufsize, stdin);

	return (buffer);
}

/**
 *
 *
 *
 *
 */

char **_tok(char *line)
{
	char *token;
	char **args = malloc(sizeof(char *) * 20);
	int positions = 0;

	printf("\n------%s-----\n", line); /*to chek progres*/

	token = strtok(line, " ");
	if(token != NULL)
	{
		while(token != NULL)
		{
			args[positions] = strdup(token);
			positions++;
			token = strtok(NULL, " ");
		}
	}
	args[positions] = NULL;
	return (args);
}

/**
 *
 *
 *
 */

int exec(char **args)
{
	int i = 0;
	pid_t pid;
	int status;

	while (args[i])
	{
		_puts(args[i]);
		i++;
	}
	
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return(1);
	}
	if (pid == 0)
	{
		if (i > 1)
		{
			execve(args[0], args, NULL);
		}
		else
		{
			perror("Error");
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
