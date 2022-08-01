#include "shell.h"

/**
 *
 */
char *pronpt(void)
{
	size_t bufsize = 512;
	char *buffer;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		exit (1);

	printf("#cisfun$ ");
	getline(&buffer, &bufsize, stdin);

	return (buffer);
}
