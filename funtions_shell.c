#include "shell.h"

/**
 *
 */
char *prompt(void)
{
	size_t bufsize = 32;
	char *buffer;

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

int exec(char *argv)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    	if (execve(argv[0], argv, NULL) == -1)
    	{
        	perror("Error:");
    	}
    	return (0);
}
