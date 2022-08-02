#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main();
int main(char argc, char **argv);
char *_getenv(const char *name);
int main(int ac, char **av, char **env);
extern char **environ;
int main(int ac, char **av);
char *_strcpy(char *dest, char *src);



#endif
