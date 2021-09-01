#ifndef _SEA_SHELL_
#define _SEA_SHELL_

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
int release(char **pathfish, char **my_argvfish, char *inputfish);

/* string_of_pearls */
int amphibian(char *tadpole);
int fish_scales(char *red_fish, char *blue_fish);
void _puts(const unsigned int n, ...);
char *str_catfish(char *one_fish, char *two_fish, char jelly_fish);
char **trawler(char *school_of_fish, char net);

/* vessels */
int catch_o_the_day(char *the_big_one, char **vessel, char **ocean);
int charter(char **vessel, char **course, char **ocean);

#endif
