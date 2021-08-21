#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void *_realloc(void *ptr, unsigned int osz, unsigned int nsz);
char **f_args(char *input);

int main(void)
{
	char p[] = "/bin/ls -l";
	char *buff, *d;
	char **my_argv;
	int exit = 1, i = 0;

	printf("%s\n", p);

	my_argv = f_args(p);

	printf ("\nout:%s  |  %s", my_argv[0], my_argv[1]);
	while(exit)
	{
		exit = 0;
	}
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
			++cnt;
			input[i] = '\0';
			arg = (input + st);
			printf("%s\n", arg);
			bufr[cnt - 1] = arg;
			st = i + 1;
		}
	}
	if (st != i)
	{
		printf("%d", cnt);
		bufr = _realloc_ptr(bufr, sizeof(char *) * cnt, sizeof(char *) * (cnt + 1));
		++cnt;
		arg = (input + st);
        bufr[cnt - 1] = arg;
		printf("%s -- %s", bufr[0], bufr[1]);
	}
	return (bufr);
}
