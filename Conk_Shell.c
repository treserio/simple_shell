#include "c_shells_by_the_c_shore.h"
#include "string_of_pearls.c"

int main(void)
{
	extern char **environ;
	char *input, *cmd_path;
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
		_puts("$ ");

		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
			_puts("input failure\n");
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
			_puts("\n");
			continue;
		}
		if (!fish_scales(my_argv[0], "path"))
		{
			for (i = 0; path[i]; ++i)
			{
				_puts(path[i]);
				if (path[i + 1])
					_puts(":");
			}
			free(my_argv);
			_puts("\n");			
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
			{
				_puts(my_argv[0]);
				_puts(": failed to start process\n");
			}
			else if (pid == 0)
			{
				if (execve(cmd_path, my_argv, environ) == -1);
				{
					free(cmd_path);
					_puts(my_argv[0]);					
					_puts(": Program failed to run.\n");
					exit(-1);
				}
			}
			else
				(waitpid(pid, &chld_exit, 0));
		}
		else
		{
			_puts(my_argv[0]);
			_puts(": command not found\n");
		}
		free(my_argv);
		free(cmd_path);
	}
	/* for exit code convert string to int */
	to_Davy_Jones_locker = amphibian(my_argv[1]);
	free(input);
	exit(to_Davy_Jones_locker);
}
/**
 * path_fishing - find the path in the environ variable
 * @ocean: the environ variable information to fish
 * Return: an array of Path strings
 */
char **path_fishing(char **ocean)
{
	int fish, part, st;
	char *catch;

	/* add pwd to 0 index and start at fish +1 */
	for (fish = 0; ocean[fish]; ++fish)
	{
		/* search for = in string */
		for (part = 0; ocean[fish][part] && ocean[fish][part] != '='; ++part)
		;
		if (ocean[fish][part] == '=')
		{
			catch = malloc(part + 1);
			/* copy over the identifier before the = */
			for (st = 0; st < part; ++st)
				catch[st] = ocean[fish][st];
			catch[st] = '\0';
			/* compare result with "PATH" */
			if(!fish_scales(catch, "PATH"))
			{
				free(catch);
				/* returned parsed path variables as array of char pntrs */
				return (trawler((ocean[fish] + (part+1)), ':'));
			}
			free(catch);
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

	for (fish = 0; ocean[fish]; ++fish)
	{
		_puts(ocean[fish]);
		if (ocean[fish + 1])
			_puts("\n");
	}		
}
/* returns the correct path or NULL if access was unsuccessfull */
char *deep_C_fishing(char *hook, char **sea)
{
	int fish;
	char *catch = NULL;

	for (fish = 0; sea[fish]; ++fish)
	{
		catch = str_catfish(sea[fish], hook);
		if (!access(catch, X_OK))
			break;
		else
			catch = NULL;
	}
	return (catch);
}