#include "c_shells_by_the_c_shore.h"
/**
 * fish_cmp - compare 2 strings
 * @red_fish: first string to compare
 * @blue_fish: second string to compare
 * Return: linguistic difference in the deviant char, or zero if match
 */
int fish_cmp(char *red_fish, char *blue_fish)
{
	int part, chk = 0;

	for (part = 0; red_fish[part] != '\0' && blue_fish[part] != '\0'; part++)
	{
		if (red_fish[part] != blue_fish[part])
			break;
	}
	chk = red_fish[part] - blue_fish[part];
	return (chk);
}
/**
 * trawler - splits string on parser and returns array of parsed str
 * @school_of_fish: the string to parse
 * @net: char to use as delimiter
 * Return: array of parsed strings
 */
char **trawler(char *school_of_fish, char net)
{
	int fish, st, cnt = 0;
	char **haul;
	char *catch;


	for (fish = 0; school_of_fish[fish]; ++fish)
	{
		if (school_of_fish[fish] == net)
			++cnt;
	}

	haul = malloc(sizeof(char *) * (cnt + 2));
	if (!haul)
		exit(-1);

	for (fish = 0, st = 0, cnt = 0; school_of_fish[fish]; ++fish)
	{
		/* to consider " or o add a check bit  */		
		if (school_of_fish[fish] == net)
		{
			school_of_fish[fish] = '\0';
			catch = (school_of_fish + st);
			haul[cnt] = catch;
			st = fish + 1;
			++cnt;
		}
	}
	/* if the last char is not a space */
	if (st != fish)
	{
		catch = (school_of_fish + st);
		haul[cnt] = catch;
		++cnt;
	}
	/* set the final value as NULL */
	haul[cnt] = NULL;

	return (haul);
}

/* convert a number string to an int value if value was passed */
int amphibian(char *tadpole)
{
	int frog = 0;

	if (tadpole)
	{
		for(; *tadpole; ++tadpole)
		{
			frog *= 10;
			frog += *tadpole - '0';
		}
	}
	return (frog);
}

/* need a strcat function here */
char *str_catfish(char *one_fish, char *two_fish)
{
	int i, size;
	char *big_fish;

	for (size = 0; one_fish[size]; ++size)
	;
	for (i = 0; two_fish[i]; ++size, ++i)
	;
	/* malloc size and copy strings to malloced buffes */
	big_fish = malloc(size + 2);

	for (size = 0; one_fish[size]; ++size)
		big_fish[size] = one_fish[size];
	big_fish[size] = '/';
	for (i = 0, ++size; two_fish[i]; ++size, ++i)
		big_fish[size] = two_fish[i];
	/* set null byte for eos */
	big_fish[size] = '\0';

	return (big_fish);
}
/**
 * _puts - prints out the str in one write call
 * @str: pointer to a string array
 * Return: void
 */
void _puts(char *str)
{
    int size = 0;
    
    while (str[size])
      ++size;

    write(1, str, size);
}
