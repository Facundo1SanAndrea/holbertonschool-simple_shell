#include "shell.h"
#include <stdlib.h>

extern char **environ;

/**
 * my_getpath - to found the value of any env
 *
 * @name: name to the var
 *
 * Return: pointer whit value requieride
 */
char *my_getpath(const char *name)
{
	int i = 0, j;
	int status = 1;

	while (environ[i])
	{
		status = 1;
		j = 0;
		while (environ[i][j] != '=')
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		j++;
		}
		if (status)
		{
			return(&environ[i][j + 1]);
		}
	i++;
	}

	return (NULL);
}


/**
 * toker_path - this functions tokenize path
 *
 * Return: path array
 */
char **toker_path(void)
{
        char **tok_path = NULL;
        char *path_coppy;
		


	path_coppy = _strdup(my_getpath("PATH"));


        tok_path = _strtok(path_coppy);


        free(path_coppy);

	

        return (tok_path);

}

/**
 * correct_path - serch the correct path
 *
 * @buff_tokens: path tokenized
 *
 * Return: alwais 0
 */
int correct_path(char **buff_tokens)
{
        int i = 0;
        char *directory;
        struct stat st;
	char **tok_path;

	tok_path = toker_path();
	
        while (tok_path[i])
        {
                directory = _strdup(tok_path[i]);
                directory = str_concat(directory, "/");
                directory = str_concat(directory, buff_tokens[0]);

                if (stat(directory, &st) == 0)
        	{
			buff_tokens[0] = _strdup(directory);
                        return (0);
                }
                i++;
        }
        return (0);
}
