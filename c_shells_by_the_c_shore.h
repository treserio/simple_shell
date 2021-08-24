#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/*Kaijus*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void depth_finder(char **);
char **path_fishing(char **);
char *deep_C_fishing(char *hook, char **sea);

/* string of pearls */
int _strcmp(char *s1, char *s2);
char **trawler(char *, char);

#endif