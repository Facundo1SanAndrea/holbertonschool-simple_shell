#include "shell.h"
#include <stdlib.h>

extern char **environ;

/**
 *
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
	printf("\n------------------\n");

	return (NULL);
}


/**
 *
 */
char **toker_path(void)
{
        char **tok_path = NULL;
        char *path_coppy;
		


	path_coppy = _strdup(my_getpath("PATH"));

	printf("tp %s", path_coppy);

        tok_path = _strtok(path_coppy);

        free(path_coppy);

	

        return (tok_path);

}

/**
 *
 *
 */
int correct_path(char **buff_tokens)
{
        int i = 0;
        char *directory;
        struct stat st;
	char **tok_path;

	tok_path = toker_path();
	if (buff_tokens[0][0] != '/')
	{
	        while (tok_path[i])
	        {
	                directory = _strdup(tok_path[i]);
	                str_concat(directory, "/");
			printf("\njlij %s\n", directory);
	                str_concat(directory, buff_tokens[0]);
			printf("\njlij %s\n", directory);
	                if (stat(directory, &st) == 0)
	        	{
				buff_tokens[0] = _strdup(directory);
				printf("\njlij %s\n", buff_tokens[0]);
	                        return (0);
	                }
	                i++;
	        }
	}
	printf("buff_tokens2 %s", buff_tokens[0]);

        return (0);
}
