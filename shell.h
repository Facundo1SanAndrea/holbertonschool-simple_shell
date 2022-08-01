#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(void);
int _which(char argc, char **argv);
int env(int ac, char **av, char **env);
int _putchar(char c);
char *prompt(void);
char **_tok(char *line);
int exec(char *argv);
void _puts(char *str);


#endif
