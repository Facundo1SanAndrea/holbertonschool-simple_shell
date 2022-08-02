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
		are_equal = true; /* seteado a 1, valor TRUE en condiciones */
		for (index = 0; environ[elem][index] != '='; index++)
		{
			if (name[index] != environ[elem][index])
			{
				are_equal = false;
				break; /* sigue al proximo elemento */
			}
		}

		if (are_equal)
		{
			/* si el valor es verdadero(comparacion exitosa),
			 * devuelve los valores luego del '=' 
			 */
			return (&environ[elem][index + 1]);
		}
	}
	return (NULL); /* en caso que no se halla encontrado nombre de la
			* variable pasada como argumento
			*/
}

/**
 *
 *
 *
 *
 */
extern char **environ;

int _printenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write (1, environ[i], 10);
	}
	return(0);
}
/**
 *
 *
 */
char **_strtok(char *buffer)
{
	int i = 0;
	char *token;	
	char **buffer_keep;
	
	buffer_keep = calloc(1024, sizeof(char *));
	token = strtok(buffer, "\n");
	token = strtok(buffer, " \t\n");

	while (token != NULL)
	{
		buffer_keep[i] = token;

		if (buffer_keep == NULL)
		{
			free (buffer_keep);
			free (token);
			free (buffer);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
		i++;
	}
	buffer_keep[i] = NULL;
	return (buffer_keep);
}
