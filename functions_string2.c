#include "shell.h"
/**
 *
 *
 */
char *strchr42a(char *str, int ch)
{
do      {
        if (*str == ch) return str;
        } while (*str++) ;
return NULL;
}
