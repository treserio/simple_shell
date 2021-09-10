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
char *deep_C_fishing(char *hook, char **sea);
void depth_finder(char **ocean);
char **path_fishing(char **ocean, char *old_port);
int release(char **p_f, char **arg_f, char *in_f, char *op_f, char *d_f);

/* string_of_pearls */
int amphibian(char *dad_frog, int fathoms, char **tadpole);
char *dive(int surface);
int fish_scales(char *red_fish, char *blue_fish);
void _puts(const unsigned int n, ...);
char *str_catfish(char *one_fish, char *two_fish, char jelly_fish);

/* vessels */
int big_catch(char *big_1, char **ship, char **ocean, char *trip, int league);
char **change_port(char *port, char **compass, char *old_port);
int charter(char **vessel, char **course, char **ocean, char *old_port);
int fish_spotter(char *school_of_fish, char net);
char **trawler(char *school_of_fish, char net);

#endif
