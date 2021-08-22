#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *_realloc(void *ptr, unsigned int osz, unsigned int nsz);
char **f_args(char *input);

int main(void)
{
	char p[] = "/bin/ls -l";
	char *input, *d;
	char **my_argv;
	int exit = 1, i = 0;
	size_t sz_input = 20;
	ssize_t chk;

	input = malloc(sizeof(char) * sz_input);
	if (!input)
		return (-1);

	while(exit)
	{

		chk = getline(&input, &sz_input, stdin);
		if (chk == -1)
			printf("input failure");

		input[chk - 1] = '\0';

		printf("%s\n", input);

		my_argv = f_args(input);

		while (my_argv[i])
		{
			printf("%s", my_argv[i]);
			++i;
		}
		printf("\n");
		printf("%s", input);
		if (input == "exit")
			exit = 0;
	}
	free(input);
	free(my_argv);
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
	int i, st, cnt = 0;
	char **bufr = malloc(cnt);
	char *arg;

	printf("in f_args:%s\n", input);

	for (i = 0, st = 0, cnt = 0; input[i]; ++i)
	{
		if (input[i] == ' ')
		{
			bufr = _realloc_ptr(bufr, sizeof(char *) * cnt, sizeof(char *) * cnt + 1);
			input[i] = '\0';
			arg = (input + st);
			bufr[cnt] = arg;
			st = i + 1;
			++cnt;
			printf("%s\n", arg);
		}
	}
	if (st != i)
	{
		bufr = _realloc_ptr(bufr, sizeof(char *) * cnt, sizeof(char *) * (cnt + 1));
		arg = (input + st);
        bufr[cnt] = arg;
		++cnt;
		printf("%s\n", arg);
		printf("%d", cnt);
	}
	bufr = _realloc_ptr(bufr, sizeof(char *) * cnt, sizeof(char *) * (cnt + 1));
	bufr[cnt] = NULL;
	++cnt;

	return (bufr);
}
