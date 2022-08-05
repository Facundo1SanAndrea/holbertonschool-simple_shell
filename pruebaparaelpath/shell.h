#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

int main();
int _printenv(void);
int main2(char argc, char **argv);
int _printenv(void);
int main3(int ac, char **av, char **env);
extern char **environ;
int main4(int ac, char **av);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char **_strtok(char *buffer);
int few(char **args);
int my_prompt(void);
void ctrl_d(int sig);
char *_getenv(const char *name);

#endif
