#include "shell.c"


/**
 * input_parse - a function that creates a string from a user input
 * @input: the string to parse
 * @arr: the array
 * @COMM: the command name
 * Return: an array of arguments
 */
char **input_parse(char *input, char **arr, char *COMM)
{
	char **commands, *tok, *path_dir = NULL;
	int num, num_args;

	num_args = counter_arg(input), commands = malloc(num_args + 1);
	if (commands == NULL)
	{
		free_arr(arr);
		return (NULL);
	}
	tok = str_tok(input, "\n ");
	if (env_check(tok) == -)
	{
		path_dir = get_path(arr, tok);
		if (path_dir == NULL)
		{
			free(commands), free_arr(arr);
			command_not_found_err(COMM, tok);
			exitcode = 127;
			return (NULL);
		}
		else if (str_cmp("access denied", path_dir) == 0)
		{
			free(commands), free_arr(arr);
			privilege_err(COMM, tok);
			exitcode = 126;
			return (NULL);
		}
		commands[0] = str_dup(path_dir);
		free(path_dir);
	}
	else
		commands[0] = str_dup(token);

	for (num = 1; num < num_args; num++)
	{
		tok = str_tok(0, "\n ");
		commands[num] = str_dup(tok);
	}
	commands[num] = NULL;
	return (commands);
}


/**
 * counter_arg - a function that counts the total number of arguments
 * @input: the user argument
 * Return: the number of arguments
 */
int counter_arg(char *input)
{
	int num, count, argument = 1;

	num = count = 0;

	while (input[num] != '\0' && input[num] != '\n')
	{
		if (input[num] != ' ')
			count = 1;

		if (input[num] == ' ' && input[num + 1] != ' '
				&& input[num + 1] != '\n' && count == 1)
			argument++;
		num++;
	}

	return (argument);
}
