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
		input = malloc(0);
		if (!input)
			return (-1);
		
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
		printf("%s", input);
		/* needs strcmp to compare input to exit case */
		if (!_strcmp(input, "exit"))
			exit = 0;
		free(input);
		free(my_argv);
	}
}

void *_realloc_ptr(void *ptr, unsigned int osz, unsigned int nsz)
{
	unsigned int i;
	char *dest, *orig = ptr;

	/* new_size == old_size rtrn ptr */
	if (osz == nsz)
		return (ptr);

	if (nsz == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		free(ptr);
		return (malloc(nsz));
	}

	dest = malloc(nsz);
	if (dest == NULL)
		return (NULL);

	/* copy values from input pointer to dest */
	for (i = 0; i < osz; ++i)
		dest[i] = orig[i];

	free(ptr);
	return (dest);
}

char **f_args(char *input)
{
	int i, st, cnt;
	char **bufr = malloc(0);
	char *arg;

	printf("in f_args:%s\n", input);

	for (i = 0, st = 0, cnt = 0; input[i]; ++i)
	{
		if (input[i] == ' ')
		{
			bufr = _realloc_ptr(bufr, sizeof(char *) * cnt, sizeof(char *) * (cnt + 1));
			if (!bufr)
			{
				printf("Realloc failed");
				exit(-1);
			}
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
		bufr = _realloc_ptr(bufr, sizeof(char *) * cnt, sizeof(char *) * (cnt + 1));
		if (!bufr)
		{
			printf("Realloc failed");
			exit(-1);
		}
		arg = (input + st);
        bufr[cnt] = arg;
		++cnt;
		printf("%s\n", arg);
		printf("%d", cnt);
	}
	bufr = _realloc_ptr(bufr, sizeof(char *) * cnt, sizeof(char *) * (cnt + 1));
	if (!bufr)
	{
		printf("Realloc failed");
		exit(-1);
	}
	bufr[cnt] = NULL;
	++cnt;

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
