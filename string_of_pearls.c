#include "c_shells_by_the_c_shore.h"
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
	chk = s1[i] - s2[i];
	return (chk);
}
/**
 * parser - splits string on parser and returns array of parsed str
 * @input: the string to parse
 * @parser: char to use as delimiter
 * Return: array of parsed strings
 */
char **parser(char *input, char parser)
{
	int i, st, cnt = 0;
	char **bufr;
	char *arg;

	printf("in parser:%s\n", input);

	for (i = 0; input[i]; ++i)
	{
		if (input[i] == parser)
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
		if (input[i] == parser)
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
