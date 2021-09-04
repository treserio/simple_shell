#include "c_shells_by_the_c_shore.h"
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
	int sunk = 0;
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
			if (ocean && execve(big_1, ship, ocean) == -1)
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
	if (WIFEXITED(sunk))
		sunk = WEXITSTATUS(sunk);
	return (sunk);
}
/**
 * change_port - changes the cwd and stores the old one in old_port
 * @port: PATH
 * @compass: my_argv
 * @old_port: previous cwd
 * Return: NULL, may swap to int for error handeling
 */
char **change_port(char *port, char **compass, char *old_port)
{
	DIR *harbor;
	/* check if first char is '-' */
	if (compass[1][0] != '-' && compass[1][0] != '~')
	{
		harbor = opendir(compass[1]);
		if(harbor)
		/*if (errno != ENOENT && errno != ENOTDIR && errno != EACCES)*/
		/* handle each check with unique error out */
		{
			closedir(harbor);
			old_port = getcwd(old_port, 600);			
			chdir(compass[1]);
			port = getcwd(port, 600);
		}
		else
		{
		}
	}
	/* make use of env[HOME] to use when given ~ first char */
	/* use stat structure of new dir to check if it's a symbolic link */
	/* find name(char *) of directory in (DIR *), or use getcwd to malloc new char *
	for old_port */
	return (NULL);
}
/**
 * charter - checks if one of our builtin functions can run
 * @vessel: my_argv, all the arguments of the user input
 * @ocean: the env variable
 * @course: the path variable
 * @old_port: previous working directory
 * Return: 0=end shell(break), 1=continue, or nothing
 */
int charter(char **vessel, char **course, char **ocean, char *old_port)
{
	int leagues;

	if (!vessel[0])
	{
		release(NULL, vessel, NULL, 0);
		return (1);
	}
	if (!fish_scales(vessel[0], "exit"))
		return (0);
	if (!fish_scales(vessel[0], "env"))
	{
		depth_finder(ocean);
		release(NULL, vessel, NULL, 0);
		_puts(1, "\n");
		return (1);
	}
	if (!fish_scales(vessel[0], "path"))
	{
		for (leagues = 1; course && course[leagues]; ++leagues)
		{
			_puts(1, course[leagues]);
			if (course[leagues + 1])
				_puts(1, ":");
		}
		release(NULL, vessel, NULL, 0);
		_puts(1, "\n");
		return (1);
	}
	if (!fish_scales(vessel[0], "cd"))
	{
		change_port(course[0], vessel, old_port);
		release(NULL, vessel, NULL, 0);		
		return (1);
	}
	return (2);
}
/**
 * fish_spotter - finds the fish(words) in a school(char *)
 * @school_of_fish: the string to parse
 * @net: char to use as delimiter
 * Return: number of fish spotted
 */
int fish_spotter(char *school_of_fish, char net)
{
	int fish, word, spotted = 0;

	for (fish = 0, word = 0; school_of_fish[fish]; ++fish)
	{
		if (!word && school_of_fish[fish] != ' ')
			word = 1;
		if (school_of_fish[fish] == net && word)
		{
			++spotted;
			word = 0;
		}
	}

	return (spotted);
}
/**
 * trawler - splits school_of_fish(char *) on net(char) and adds to array
 * @school_of_fish: the string to parse
 * @net: char to use as delimiter
 * Return: array of parsed strings
 */
char **trawler(char *school_of_fish, char net)
{
	int fish, st, catch = 0, word, i;
	char **haul;

	catch = fish_spotter(school_of_fish, net);
	haul = malloc(sizeof(char *) * (catch + 2));
	for (fish = 0, st = 0, catch = 0, word = 0; school_of_fish[fish]; ++fish)
	{
		if (!word && school_of_fish[fish] == ' ')
			++st;
		if (!word && school_of_fish[fish] != ' ')
			word = 1;
		if (school_of_fish[fish] == net && word)
		{
			school_of_fish[fish] = '\0';
			haul[catch] = malloc(fish + 1);
			for (i = 0; *(school_of_fish + st + i) ; ++i)
				haul[catch][i] = *(school_of_fish + st + i);
			haul[catch][i] = '\0';
			st = fish + 1;
			++catch, word = 0;
		}
	}
	if (st != fish && word)
	{
		haul[catch] = malloc(fish + 1);
		for (i = 0; *(school_of_fish + st + i); ++i)
			haul[catch][i] = *(school_of_fish + st + i);
		haul[catch][i] = '\0';
		++catch;
	}
	haul[catch] = NULL;
	if (catch == 0)
		haul[1] = NULL;
	return (haul);
}
