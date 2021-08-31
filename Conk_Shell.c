#include "c_shells_by_the_c_shore.h"
#include "string_of_pearls.c"
/**
 * main - a POSIX complient shell
 * @ocean: the environ variable information to fish
 * Return: the exit code given by the user when exit cmnd is given
 */
int main(void)
{
	char *input = 0, *cmd_path = NULL;
	char **my_argv, **path;
	int swimming = 1, i, to_Davy_Jones_locker, chld_exit;
	size_t sz_input = 0;
	ssize_t chk;
	pid_t pid;

	/* establish global path variable */
	path = path_fishing(environ);

	/* do we need to isatty */
	while (swimming)
	{
		if (isatty(STDIN_FILENO))
			_puts(2, path[0], "$ ");
		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
		{
			my_argv = NULL;
			swimming = 0;
			break;
		}
		/* rmv newline from input */
		input[chk - 1] = '\0';
		if (!input[0])
			continue;
		/* grab array of arguments */
		my_argv = trawler(input, ' ');
		/* needs strcmp to compare input to exit case */
		if (!fish_scales(my_argv[0], "exit"))
		{
			swimming = 0;
			break;
		}
		if (!fish_scales(my_argv[0], "env"))
		{
			depth_finder(environ);
			free(my_argv);
			_puts(1, "\n");
			continue;
		}
		if (!fish_scales(my_argv[0], "path"))
		{
			for (i = 0; path[i]; ++i)
			{
				_puts(1, path[i]);
				if (path[i + 1])
					_puts(1, ":");
			}
			free(my_argv);
			_puts(1, "\n");
			continue;
		}
		/* confirm the argv[0] is a system function before execve */
		cmd_path = deep_C_fishing(my_argv[0], path);
		/* run the execve with the argv[0] + the rest of the variables */
		if (cmd_path && my_argv[0][0])
		{
			/* fork process and run execve in child, break into exe func? */
			pid = fork();
			if (pid < 0)
				_puts(2, my_argv[0], ": failed to start process\n");

			else if (pid == 0)
			{
				if (execve(cmd_path, my_argv, environ) == -1)
				{
					_puts(2, my_argv[0], ": Program failed to run.\n");
					exit(-1);
				}
			}
			else
				(waitpid(pid, &chld_exit, 0));
		}
		else
			_puts(2, my_argv[0], ": command not found or permission denied\n");

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
		/* path[0][0] = current working directory, need to figure out how to find */
	}

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
 * Return: void
 */
int release(char **pathfish, char **my_argvfish, char *inputfish)
{
	int to_Davy_Jones_locker;

	/* for exit code convert string to int */
	if (my_argvfish)
		to_Davy_Jones_locker = amphibian(my_argvfish[1]);

	free(inputfish);
	free(my_argvfish);
	/* only free path[0] since the rest are part of environ */
	free(pathfish[0]);
	free(pathfish);

	return (to_Davy_Jones_locker);
}