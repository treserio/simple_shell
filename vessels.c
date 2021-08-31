/**
 * charter - checks if one of our builtin functions can run
 * @vessel: my_argv, all the arguments of the user input
 * @course: the path variable
 * @ocean: the environ variable
 * Return: 0=end shell(break), 1=continue, or nothing
 */
int charter(char **vessel, char **course, char **ocean)
{
	int leagues;

	if (!fish_scales(vessel[0], "exit"))
		return (0);
	if (!fish_scales(vessel[0], "env"))
	{
		depth_finder(ocean);
		free(vessel);
		_puts(1, "\n");
		return (1);
	}
	if (!fish_scales(vessel[0], "path"))
	{
		for (leagues = 0; course[leagues]; ++leagues)
		{
			_puts(1, course[leagues]);
			if (course[leagues + 1])
				_puts(1, ":");
		}
		free(vessel);
		_puts(1, "\n");
		return (1);
	}
	if (!fish_scales(vessel[0], "cd"))
	{
		/* call cd function here */
		return (1);
	}
}
/*
 * cd command to change path[0] value
 * int change_port(char **course)
 * {}
 */

/**
 * catch_o_the_day - starts a child process and runs the_big_one(cmd_path)
 * @the_big_one: catch(cmd_path) pulled from deep_C_fishing(my_argv[0])
 * @vessel: my_argv, the arguments of the user input
 * @ocean: the environ variable
 * Return: the exit code of the forked process
 */
int catch_o_the_day(char *the_big_one, char **vessel, char **ocean)
{
	pid_t dingy;
	int sunk;

	/* run the execve with the argv[0] + the rest of the arguements */
	if (the_big_one)
	{
		/* launch dingy to run child process and wait for it to sink */
		dingy = fork();
		if (dingy < 0)
			_puts(2, vessel[0], ": failed to start process\n");
		else if (dingy == 0)
		{
			if (execve(the_big_one, vessel, ocean) == -1)
			{
				_puts(2, vessel[0], ": Program failed to run.\n");
				exit(-1);
			}
		}
		else
			(waitpid(dingy, &sunk, 0));
	}
	else
		_puts(2, vessel[0], ": command not found or permission denied\n");

	return (sunk);
}
