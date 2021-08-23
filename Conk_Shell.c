#include "c_shells_by_the_c_shore.h"
#include "string_of_pearls.c"

int main(void)
{
	extern char **environ;
	char *input, **path;
	char **my_argv;
	int exiting = 1, i;
	size_t sz_input = 0;
	ssize_t chk;

	while(exiting)
	{
		/* establish global variable */
		path = path_fishing(environ);

		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
			printf("input failure");
		/* rmv newline from input */
		input[chk - 1] = '\0';
		/* grab array of arguments */
		my_argv = parser(input, ' ');
		/* needs strcmp to compare input to exit case */
		if (!_strcmp(my_argv[0], "exit"))
		{
			exiting = 0;
		}
		if (!strcmp(my_argv[0], "env"))
		{
			depth_finder(environ);
		}
		if (!strcmp(my_argv[0], "path"))
		{
			path_fishing(environ);
		}
		free(my_argv);
	}
	free(input);
	/* convert string to int value for exit code */
	/* exit(my_argv[1]); */
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
		/* rewrite for condition to stop at = */
		for (j = 0; ocean[i][j]; ++j)
		{
			if (ocean[i][j] == '=')
			{
				temp = malloc(j + 1);
				for (st = 0; st < j; ++st)
					temp[st] = ocean[i][st];
				temp[st] = '\0';

				if(!_strcmp(temp, "PATH"))
				{
					free(temp);
					return (parser((ocean[i] + (j+1)), ':'));
				}
				free(temp);
			}
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
	int i;

	for (i = 0; ocean[i]; ++i)
		printf("%s\n", ocean[i]);
}
