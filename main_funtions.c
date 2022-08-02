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

