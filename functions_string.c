#include "shell.h"
/**
 *_strcpy - function that copies the string pointed to by src, including the
 *terminating null byte (\0), to the buffer pointed to by dest
 *@dest: buffer to be pointed to
 *@src: text
 *Return: copied text
 */
char *_strcpy(char *dest, char *src)
{
	char *start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (start);
}

/**
 *_strlen - returns the length of a string
 *@s: string
 *Return: length
 */
int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;
	return (c);
}

/**
 *_strdup - main function of strdup
 *@str: string
 *Return: pointer to allocated memory
 */
char *_strdup(char *str)
{
	char *result;
	char *prsc = str;
	char *pdst;

	if (str == NULL)
	{
		return (NULL);
	}

	result = malloc(_strlen(str) + 1);
	pdst = result;

	if (result == NULL)
	{
		return (NULL);
	}
	else
	{
		while (*prsc != 0)
		{
			*pdst = *prsc;
			pdst++;
			prsc++;
		}
		*pdst = '\0';
	}
	return (result);
	free(result);

}
/**
 *_strcmp - function that compares strings
 *@s1: first sring
 *@s2: second string
 *Return: diference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int diff = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		diff = (s1[i] - s2[i]);

		if (diff != 0)
			break;
	}
	if (diff == 0)
		return (0);
return (diff);
}
/**
 *str_concat - main function to concatenate
 *@s1: string one
 *@s2: string two
 *Return: pointer to allocated memory
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *result;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	result = malloc(sizeof(char) * _strlen(s1) + _strlen(s2) + 1);

	if (result == NULL)
	{
		return (NULL);
	}

	else
	{
		for (i = 0; i < _strlen(s1); i++)
		{
			result[i] = s1[i];
		}
		for (j = 0; j < _strlen(s2); j++)
		{
			result[i + j] = s2[j];
		}
		result[i + j] = '\0';
	}
	free(result);
	return (result);
}
