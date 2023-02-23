#include "shell.c"


/**
 * main - the main function
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: array of environment variables
 * Return: 0 as Success
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char **input = **commands = **arr = NULL, *COMM = argv[0];
	char *splash_file = "splash.txt";
	size_t num = 0;
	ssize_t b_read = 0;
	int atty = isatty(0), exitcode = errocount = 0;
	File *ptr_f = NULL;

	signal(SIGINT, SIG_IGN), ptr_f = fopen(splash_file, "r");
	if (ptr_f == NULL)
	{
		fprintf(stderr, "error opening file %s\n", splash_file);
		return (1);
	}
	splash_display(ptr_f), fclose(ptr_f);
	while (1)
	{
		errorcount++;
		if (atty)
			write(1, "WELCOME TO sHELl", 13);
		b_read = getline(&input, &num, stdin);
		if (b_read == -1)
			free(input), exit(exitcode);
		if (return_check(input, COMM) == -1)
			continue;
		if (path_check(input) == 1)
			continue;
		if (exit_check(input) == 1)
		{
			get_env(env);
			continue;
		}
		arr = path_array(env);
		commands = input_parse(input, arr, COMM);
		if (commands != NULL)
		{
			process_fork(commands, arr, env, COMM, input);
			free_arr(commands), free_arr(arr);
		}
	}
	return (0);
}
