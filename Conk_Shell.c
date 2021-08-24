#include "c_shells_by_the_c_shore.h"
#include "string_of_pearls.c"

int main(void)
{
	extern char **environ;
	char *input, **path;
	char **my_argv;
	int exiting = 1, i, ex_code;
	size_t sz_input = 0;
	ssize_t chk;

	/* establish global path variable */
	path = path_fishing(environ);

	while(exiting)
	{
		printf("\n$ ");

		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
			printf("input failure");
		/* rmv newline from input */
		input[chk - 1] = '\0';
		/* grab array of arguments */
		my_argv = trawler(input, ' ');
		/* needs strcmp to compare input to exit case */
		if (!_strcmp(my_argv[0], "exit"))
		{
			exiting = 0;
			break;
		}
		if (!strcmp(my_argv[0], "env"))
		{
			depth_finder(environ);
		}
		if (!strcmp(my_argv[0], "path"))
		{
			for (i = 0; path[i]; ++i)
			{
				printf("%s", path[i]);
				if (path[i + 1])
					printf(":");
			}
		}
		/* confirm the argv[0] is a system function before execve */
		/* run the execve with the argv[0] + the rest of the variables */
		execve(my_argv[0], my_argv, environ);

		free(my_argv);
	}
	/* convert string to int value for exit code */
	if (my_argv[1])
	{
		ex_code = amphibian(my_argv[1]);
		free(input);
		exit(ex_code);
	}
	free(input);
}
/**
 * path_fishing - find the path in the environ variable
 * @ocean: the environ variable information to trawl
 * Return: an array of Path strings
 */
char **path_fishing(char **ocean)
{
	int i, j, st;
	char *temp;
	char **path_array;

	for (i = 0; ocean[i]; ++i)
	{
		/* search for = in string */
		for (j = 0; ocean[i][j] && ocean[i][j] != '='; ++j)
		;
		if (ocean[i][j] == '=')
		{
			temp = malloc(j + 1);
			/* copy over the identifier before the = */
			for (st = 0; st < j; ++st)
				temp[st] = ocean[i][st];
			temp[st] = '\0';
			/* compare result with "PATH" */
			if(!_strcmp(temp, "PATH"))
			{
				free(temp);
				/* returned parsed path variables as array of char pntrs */
				return (trawler((ocean[i] + (j+1)), ':'));
			}
			free(temp);
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
	int i = 0;

	for (; ocean[i]; ++i)
		printf("%s\n", ocean[i]);
}

char *deep_c_fishing(char *hook, char **sea)
{
	
}