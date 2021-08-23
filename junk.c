#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int osz, unsigned int nsz);
char **f_args(char *input);

int main(void)
{
	char *input;
	char **my_argv;
	int exit = 1, i;
	size_t sz_input = 0;
	ssize_t chk;

	while(exit)
	{
		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
			printf("input failure");

		input[chk - 1] = '\0';

		printf("%s\n", input);

		my_argv = f_args(input);

		i = 0;
		while (my_argv[i])
		{
			printf("%s", my_argv[i]);
			++i;
		}
		printf("\n");
		/* needs strcmp to compare input to exit case */
		if (!_strcmp(input, "exit"))
		{
			printf("exiting\n");
			exit = 0;
		}
		free(my_argv);
	}
	free(input);
}
char **f_args(char *input)
{
	int i, st, cnt = 0;
	char **bufr;
	char *arg;

	printf("in f_args:%s\n", input);

	for (i = 0; input[i]; ++i)
	{
		if (input[i] == ' ')
			++cnt;
	}
	printf("cnt %d\n", cnt);
	bufr = malloc(sizeof(char *) * (cnt + 2));
	if (!bufr)
	{
		printf("check");
		exit(-1);
	}

	for (i = 0, st = 0, cnt = 0; input[i]; ++i)
	{
		if (input[i] == ' ')
		{
			input[i] = '\0';
			arg = (input + st);
			bufr[cnt] = arg;
			st = i + 1;
			++cnt;
			printf("%s\n", arg);
		}
	}
	/* if the last char is not a space */
	if (st != i)
	{
		arg = (input + st);
        bufr[cnt] = arg;
		++cnt;
		printf("%s\n", arg);
		printf("%d |", cnt);
	}

	bufr[cnt] = NULL;

	return (bufr);
}
/**
 * _strcmp - compare 2 strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: linguistic difference in the deviant char, or zero if match
 */
int _strcmp(char *s1, char *s2)
{
	int i, chk = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			chk = s1[i] - s2[i];
			break;
		}
	}

	return (chk);
}
