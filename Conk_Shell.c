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
	int sailing = 1, to_Davy_Jones_locker = 0, league = 0, chld_exit = 0;
	size_t sz_input = 0;
	ssize_t chk = 0;
	char *old_port = malloc(600), *dock = malloc(600);
	/* establish global path variable */
	path = path_fishing(environ, dock);
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
		input[chk - 1] = '\0';
		my_argv = trawler(input, ' ');
		chk = charter(my_argv, path, environ, old_port);
		if (chk == 0)
			break;
		else if (chk == 1)
			continue;
		/* confirm the argv[0] is a system function before execve */
		cmd_path = deep_C_fishing(my_argv[0], path);
		chld_exit = big_catch(cmd_path, my_argv, environ, sh_argv[0], league);
		if (my_argv)
			free(cmd_path), release(NULL, my_argv, NULL, NULL, NULL);
	}
	if (chk == 0 && my_argv[1])
		to_Davy_Jones_locker = amphibian(sh_argv[0], league, my_argv);
	else
		to_Davy_Jones_locker = chld_exit;
	release(path, my_argv, input, old_port, dock);
	return (to_Davy_Jones_locker);
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
		for (fish = 0; sea && sea[fish]; ++fish)
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
 * depth_finder - print the environment info
 * @ocean: the environ variable information
 * Return: void
 */
void depth_finder(char **ocean)
{
	int fish;

	for (fish = 0; ocean && ocean[fish]; ++fish)
	{
		_puts(1, ocean[fish]);
		if (ocean[fish + 1])
			_puts(1, "\n");
	}
}
/**
 * path_fishing - make a path variable with wdir and values in environ var
 * @ocean: the environ variable information to fish
 * @dock: buffer to store cwd
 * Return: an array of Path strings
 */
char **path_fishing(char **ocean, char *dock)
{
	int fish, part, st, pwd = 0;
	char *net, *catch, **haul;
	/* pull our cwd, up to 600 chars */
	getcwd(dock, 600);
	if (dock)
		pwd = 1;
	/* add pwd to 0 index and start at fish +1 */
	for (fish = 0; ocean && ocean[fish]; ++fish)
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
			/* compare result with "PATH" */
			if (!fish_scales(net, "PATH") && pwd)
			{
				free(net);
				catch = str_catfish("temp", (ocean[fish] + (part + 1)), ':');
				haul = trawler(catch, ':');
				free(catch);
				free(haul[0]);
				haul[0] = dock;
				/* returned parsed path variables as array of char pntrs */
				return (haul);
			}
			free(net);
		}
	}
	return (NULL);
}
/**
 * release - free the memory we've caught
 * @p_f: path_fish to release, release p_f and all indexes therein
 * @arg_f: my_argv_fish to release, release p_f and all indexes therein
 * @in_f: input_fish from getline to release
 * @op_f: old_port_fish to release
 * @d_f: dock_fish(p_f[0]) to release if p_f = NULL
 * Return: the value to use as the exit code
 */
int release(char **p_f, char **arg_f, char *in_f, char *op_f, char *d_f)
{
	int to_Davy_Jones_locker = 0, caught;

	if (p_f)
	{
		for (caught = 0; p_f && p_f[caught]; ++caught)
			free(p_f[caught]);
		free(p_f);
	}
	else
	{
		if (d_f)
			free(d_f);
	}

	if (arg_f)
	{
		for (caught = 0; arg_f && arg_f[caught]; ++caught)
		{
			free(arg_f[caught]);
		}
		free(arg_f[caught]);
		free(arg_f);
	}
	if (in_f)
		free(in_f);

	if (op_f)
		free(op_f);

	return (to_Davy_Jones_locker);
}
