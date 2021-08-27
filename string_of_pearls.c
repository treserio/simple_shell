#include "c_shells_by_the_c_shore.h"
/**
 * fish_scales - weigh fish and return difference, or 0 if they're =
 * @red_fish: first string to compare
 * @blue_fish: second string to compare
 * Return: linguistic difference in the deviant char, or zero if match
 */
int fish_scales(char *red_fish, char *blue_fish)
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
char *str_catfish(char *one_fish, char *two_fish, char jelly_fish)
{
	int i, size;
	char *catfish;

	for (size = 0; one_fish[size]; ++size)
	;
	for (i = 0; two_fish[i]; ++size, ++i)
	;
	/* if jelly_fish then malloc size + 2, else + 1 */	
	if (jelly_fish)
		catfish = malloc(size + 2);
	else
		catfish = malloc(size + 1);
	/* copy strings to buffers */
	for (size = 0; one_fish[size]; ++size)
		catfish[size] = one_fish[size];
	/* if jelly_fish then insert jelly_fish between fish */
	if (jelly_fish)
	{
		catfish[size] = jelly_fish;
		++size;
	}
	for (i = 0; two_fish[i]; ++size, ++i)
		catfish[size] = two_fish[i];
	/* set null byte for eos */
	catfish[size] = '\0';

	return (catfish);
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
