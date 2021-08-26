#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/*Kaijus*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void depth_finder(char **);
char **path_fishing(char **);
char *deep_C_fishing(char *hook, char **sea);

/* string of pearls */
int fish_scales(char *red_fish, char *blue_fish);
char **trawler(char *, char);
char *str_catfish(char *one_fish, char *two_fish);

#endif