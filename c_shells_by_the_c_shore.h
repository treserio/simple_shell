#ifndef _SEA_SHELL_
#define _SEA_SHELL_

/* Kaijus */
#include <dirent.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern char **environ;

/* Conk_Shell */
void depth_finder(char **ocean);
char **path_fishing(char **ocean, char *old_port);
char *deep_C_fishing(char *hook, char **sea);
int release(char **pathfish, char **my_argvfish, char *inputfish, int end);

/* string_of_pearls */
int amphibian(char *tadpole);
char *dive(int surface);
int fish_scales(char *red_fish, char *blue_fish);
void _puts(const unsigned int n, ...);
char *str_catfish(char *one_fish, char *two_fish, char jelly_fish);

/* vessels */
int big_catch(char *big_1, char **ship, char **ocean, char *trip, int league);
int charter(char **vessel, char **course, char **ocean, char *old_port);
char **trawler(char *school_of_fish, char net);
char **change_port(char *port, char **compass, char *old_port);

#endif
