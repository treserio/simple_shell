#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/* Kaijus */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

extern char **environ;

/* Conk_Shell */
void depth_finder(char **ocean);
char **path_fishing(char **ocean);
char *deep_C_fishing(char *hook, char **sea);
void release(char **caught);

/* string_of_pearls */
int fish_scales(char *red_fish, char *blue_fish);
char **trawler(char *school_of_fish, char net);
char *str_catfish(char *one_fish, char *two_fish, char jelly_fish);
void _puts(const unsigned int n, ...);

#endif