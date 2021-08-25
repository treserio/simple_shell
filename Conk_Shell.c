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
	while(swimming)
	{
		_puts("\n$ ");

		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
			_puts("input failure");
		/* rmv newline from input */
		input[chk - 1] = '\0';
		/* grab array of arguments */
		my_argv = trawler(input, ' ');
		/* needs strcmp to compare input to exit case */
		if (!fish_cmp(my_argv[0], "exit"))
		{
			swimming = 0;
			break;
		}
		if (!fish_cmp(my_argv[0], "env"))
		{
			depth_finder(environ);
			free(my_argv);
			continue;
		}
		if (!fish_cmp(my_argv[0], "path"))
		{
			for (i = 0; path[i]; ++i)
			{
				_puts(path[i]);
				if (path[i + 1])
					_puts(":");
			}
			free(my_argv);
			continue;
		}
		/* confirm the argv[0] is a system function before execve */
		cmd_path = deep_C_fishing(my_argv[0], path);
		/* run the execve with the argv[0] + the rest of the variables */
		if (cmd_path)
		{
			/* fork process and run execve in child, break into exe func? */
			pid = fork();
			if (pid < 0)
			{
				_puts("Unable to start process: ");
				_puts(my_argv[0]);
			}
			else if (pid == 0)
				execve(cmd_path, my_argv, environ);
			else
				(waitpid(pid, &chld_exit, 0));
			printf("exit status:%d", chld_exit);
		}
		else
		{
			_puts(my_argv[0]);
			_puts(": command not found");
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
			if(!fish_cmp(catch, "PATH"))
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
		printf("catch:%s\n", catch);
		if (!access(catch, X_OK))
			break;
		else
			catch = NULL;
	}
	return (catch);
}