#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/*Kaijus*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void depth_finder(char **);
char **path_fishing(char **);

/* string of pearls */
int _strcmp(char *s1, char *s2);
char **parser(char *, char);

#endif