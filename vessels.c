#include "c_shells_by_the_c_shore.h"
/**
 * charter - checks if one of our builtin functions can run
 * @vessel: my_argv, all the arguments of the user input
 * @course: the path variable
 * @ocean: the environ variable
 * Return: 0=end shell(break), 1=continue, or nothing
 */
int charter(char **vessel, char **course, char **ocean)
{
	int leagues;
	if (!vessel[0])
	{
		free(vessel);
		return (1);
	}
	if (!fish_scales(vessel[0], "exit"))
		return (0);
	if (!fish_scales(vessel[0], "env"))
	{
		depth_finder(ocean);
		free(vessel);
		_puts(1, "\n");
		return (1);
	}
	if (!fish_scales(vessel[0], "path"))
	{
		for (leagues = 0; course[leagues]; ++leagues)
		{
			_puts(1, course[leagues]);
			if (course[leagues + 1])
				_puts(1, ":");
		}
		free(vessel);
		_puts(1, "\n");
		return (1);
	}
	if (!fish_scales(vessel[0], "cd"))
	{
		/* call cd function here */
		return (1);
	}
	return (2);
}
/*
 * cd command to change path[0] value
 * int change_port(char **course)
 * {}
 */

/**
 * big_catch - starts a child process and runs big_1(cmd_path)
 * @big_1: catch(cmd_path) pulled from deep_C_fishing(my_argv[0])
 * @ship: my_argv, the arguments of the user input
 * @ocean: the environ variable
 * @trip: the name of the executing code
 * @fathoms: the number of lines read in the shell
 * Return: the exit code of the forked process
 */
int big_catch(char *big_1, char **ship, char **ocean, char *trip, int fathoms)
{
	pid_t dingy;
	int sunk;
	char *submurged;
	/* run the execve with the argv[0] + the rest of the arguements */
	if (big_1)
	{
		/* launch dingy to run child process and wait for it to sink */
		dingy = fork();
		if (dingy < 0)
			_puts(2, ship[0], ": failed to start process\n");
		else if (dingy == 0)
		{
			if (execve(big_1, ship, ocean) == -1)
			{
				_puts(6, trip, ": ", dive(fathoms), ": ", ship[0], ": not found\n");
				exit(-1);
			}
		}
		else
			(waitpid(dingy, &sunk, 0));
	}
	else
	{
		submurged = dive(fathoms);
		_puts(6, trip, ": ", submurged, ": ", ship[0], ": not found\n");
		free(submurged);
	}
	sunk = WEXITSTATUS(sunk);
	return (sunk);
}
/**
 * trawler - splits school_of_fish(char *) on net(char) and adds to array
 * @school_of_fish: the string to parse
 * @net: char to use as delimiter
 * Return: array of parsed strings
 */
char **trawler(char *school_of_fish, char net)
{
	int fish, st, cnt = 0, word = 0;
	char **haul;
	char *catch;

	for (fish = 0; school_of_fish[fish]; ++fish)
	{
		if (!word && school_of_fish[fish] != ' ')
			word = 1;
		if (school_of_fish[fish] == net && word)
		{
			++cnt;
			word = 0;
		}
	}
	haul = malloc(sizeof(char *) * (cnt + 2));
	if (!haul)
		exit(-1);
	for (fish = 0, st = 0, cnt = 0, word = 0; school_of_fish[fish]; ++fish)
	{
		if (!word && school_of_fish[fish] == ' ')
			++st;
		if (!word && school_of_fish[fish] != ' ')
			word = 1;
		/* to consider " or ' add a check bit */
		if (school_of_fish[fish] == net && word)
		{
			school_of_fish[fish] = '\0';
			catch = (school_of_fish + st);
			haul[cnt] = catch;
			st = fish + 1;
			++cnt;
			word = 0;
		}
	}
	/* if the last char is not a space */
	if (st != fish && word)
	{
		catch = (school_of_fish + st);
		haul[cnt] = catch;
		++cnt;
	}
	/* set the final value as NULL */
	haul[cnt] = NULL;
	return (haul);
}
