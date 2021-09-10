#include "c_shells_by_the_c_shore.h"
/**
 * amphibian - turns a tadpole(char *) into a frog(int)
 * @dad_frog: the sh_argv of the executing shell
 * @fathoms: the number of commands run by the shell
 * @tadpole: the numeric char str to convert to int
 * Return: the frog(int)
 */
int amphibian(char *dad_frog, int fathoms, char **tadpole)
{
	char *depth;
	int frog = 0, age;

	if (tadpole[1] && tadpole[1][0] == '-')
	{
		depth = dive(fathoms);
		_puts(2, 6, dad_frog, ": ", depth, ": ", tadpole[0], ": illegal number: ");
		_puts(2, 2, tadpole[1], "\n");
		free(depth);
		return (2);
	}
	if (tadpole[1])
	{
		for (age = 0; tadpole[1][age]; ++age)
		{
			if (tadpole[1][age] >= '0' && tadpole[1][age] <= '9')
			{
				frog *= 10;
				frog += tadpole[1][age] - '0';
			}
			else
			{
				depth = dive(fathoms);
				_puts(2, 6, dad_frog, ": ", depth, ": ", tadpole[0], ": illegal number: ");
				_puts(2, 2, tadpole[1], "\n");
				free(depth);
				return (2);
			}
		}
	}
	return (frog);
}
/**
 * dive - turns an integer into a string
 * @surface: integer to convert to string
 * Return: depth, the converted value
 */
char *dive(int surface)
{
	unsigned int fathom = 0, distance, neg = 0;
	char *depth;

	if (surface < 0)
	{
		surface *= -1;
		neg = 1;
	}
	for (distance = 1; (surface / distance) >= 10; distance *= 10)
	;
	depth = malloc(distance + 1);
	if (neg)
	{
		depth[fathom] = '-';
		++fathom;
	}
	for (; distance >= 1; surface %= distance, distance /= 10, ++fathom)
		depth[fathom] = (surface / distance) + '0';

	depth[fathom] = '\0';
	return (depth);
}
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
 * _puts - writes to the fd one input str at a time
 * @fd: 1 = stdout, 2 = stderr
 * @n: the number of (char *) given to _puts to print
 * Return: void
 */
void _puts(const int fd, const unsigned int n, ...)
{
	unsigned int size, i;
	char *str;
	va_list str_array;

	va_start(str_array, n);

	for (i = 0, size = 0; i < n; ++i, size = 0)
	{
		str = va_arg(str_array, char *);

		if (str[size])
		{
			while (str[size])
				++size;
		}

		write(fd, str, size);
	}

	va_end(str_array);
}
/**
 * str_catfish - concatonates 2 strings with a potential insert
 * @one_fish: first string to use in creating catfish
 * @two_fish: second string to use in creating catfish
 * @jelly_fish: char to insert between one_fish & two_fish
 * Return: pointer to allocated memory containing catfish
 */
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
