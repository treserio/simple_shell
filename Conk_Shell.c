#include "c_shells_by_the_c_shore.h"
/**
 * main - a POSIX complient shell
 * @sh_ac: number of arguments fed the shell
 * @sh_argv: arguments fed shell as an array of strings
 * Return: the exit code given by the user when exit cmnd is given
 */
int main(__attribute__((unused))int sh_ac, char **sh_argv)
{
	char **path = NULL, **my_argv = NULL, *input = 0, *cmd_path = NULL;
	int sailing = 1, to_Davy_Jones_locker, league = 0; /*chld_exit*/
	size_t sz_input = 0;
	ssize_t chk;
	/* establish global path variable */
	path = path_fishing(environ);
	while (sailing)
	{
		if (isatty(STDIN_FILENO))
			_puts(2, path[0], "$ ");
		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
		{
			my_argv = NULL;
			break;
		}
		++league;
		/* rmv newline from input */
		input[chk - 1] = '\0';
		/* checking staces & blank entries */
		if (!input[0] || input[0] == ' ')
			continue;
		/* grab array of arguments */
		my_argv = trawler(input, ' ');
		/* check for builtins and takes appropriate action */
		chk = charter(my_argv, path, environ);
		if (chk == 0)
			break;
		else if (chk == 1)
			continue;
		/* confirm the argv[0] is a system function before execve */
		cmd_path = deep_C_fishing(my_argv[0], path);
		/* run the command */
		catch_o_the_day(cmd_path, my_argv, environ, sh_argv[0], league);
		free(cmd_path);
		free(my_argv);
	}
	to_Davy_Jones_locker = release(path, my_argv, input);
	exit(to_Davy_Jones_locker);
}
/**
 * path_fishing - make a path variable with wdir and values in environ var
 * @ocean: the environ variable information to fish
 * Return: an array of Path strings
 */
char **path_fishing(char **ocean)
{
	int fish, part, st, pwd = 0;
	char *net, *catch, **haul;

	/* confirm that there is an ocean to swim in */
	if (!ocean)
	{
	} /*path[0][0] = current working directory, need to figure out how to find*/
	/* add pwd to 0 index and start at fish +1 */
	for (fish = 0; ocean[fish]; ++fish)
	{
		/* search for = in string */
		for (part = 0; ocean[fish][part] && ocean[fish][part] != '='; ++part)
		;
		if (ocean[fish][part] == '=')
		{
			net = malloc(part + 1);
			/* copy over the identifier before the = */
			for (st = 0; st < part; ++st)
				net[st] = ocean[fish][st];
			net[st] = '\0';
			/* compare result with PWD to locate working directory */
			if (!fish_scales(net, "PWD") && !pwd)
			{
				catch = (ocean[fish] + (part + 1));
				pwd = 1;
				fish = 0;
			}
			/* compare result with "PATH" */
			if (!fish_scales(net, "PATH") && pwd)
			{
				free(net);
				catch = str_catfish(catch, (ocean[fish] + (part + 1)), ':');
				haul = trawler(catch, ':');
				/* returned parsed path variables as array of char pntrs */
				return (haul);
			}
			free(net);
		}
	}
	return (NULL);
}
/**
 * depth_finder - print the environment info
 * @ocean: the environ variable information
 * Return: void
 */
void depth_finder(char **ocean)
{
	int fish;
	/* if !ocean put env variable empty or missing? */

	for (fish = 0; ocean[fish]; ++fish)
	{
		_puts(1, ocean[fish]);
		if (ocean[fish + 1])
			_puts(1, "\n");
	}
}
/**
 * deep_C_fishing - look through path strings for the input cmnd to run
 * @hook: the argv[0] value, or cmnd expected to run
 * @sea: the array of strings stored in path
 * Return: full path of accessable cmnd, else NULL if missing or unable to exe
 */
char *deep_C_fishing(char *hook, char **sea)
{
	int fish;
	char *catch = NULL;

	/* if the hook[0] is a . or a / return it as the path */
	if (hook[0] == '/' || hook[0] == '.')
	{
		catch = str_catfish(hook, "", 0);
		if (access(catch, X_OK))
			catch = NULL;
	}
	else
	{
		for (fish = 0; sea[fish]; ++fish)
		{
			catch = str_catfish(sea[fish], hook, '/');
			if (!access(catch, X_OK))
				break;
			free(catch);
			catch = NULL;
		}
	}
	return (catch);
}
/**
 * release - free the memory we've caught
 * @pathfish: the path variable and path[0], the rest belong to environ
 * @my_argvfish: the location for our my_argv variable
 * @inputfish: the input from getline
 * Return: the value to use as the exit code
 */
int release(char **pathfish, char **my_argvfish, char *inputfish)
{
	int to_Davy_Jones_locker = 0;

	/* for exit code convert string to int */
	if (my_argvfish && my_argvfish[1])
		to_Davy_Jones_locker = amphibian(my_argvfish[1]);

	free(inputfish);
	if (my_argvfish)
		free(my_argvfish);

	/* only free path[0] since the rest are part of environ */
	free(pathfish[0]);
	free(pathfish);

	return (to_Davy_Jones_locker);
}
