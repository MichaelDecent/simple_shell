#include "shell.h"

/**
 * return_check - a function that compares the user input for return command
 * @input: the command
 * Return: 0 if command is '\n' and 1 otherwise
 */

int return_check(char *input)
{
	if (input != '\n')
		return (1);

	return (0);
}


/**
 * path_check - a function that compares the user input for path
 * @p: the command
 * Return: 0 if command is '/' and 1 otherwise
 */
int path_check(char *p)
{
	if (p[0] != '/')
		return (1);

	return (0);
}


/**
 * env_check - a function that comapers the user input with env
 * @input: the command
 * Return: 0 if command is env otherwise 1
 */
int env_check(char *input)
{
	int num;
	char *env = "env";

	if (str_len(input) != 4)
		return (1);

	for (num = 0; env[num]; num++)
	{
		if (env[num] != input[num])
			return (1);
	}

	return (0);
}


/**
 * exit_check - a function that exits the shell if exit command is given
 * @input: the command
 * @COMM: the command name
 * Return: 0 for exit otherwise -1
 */
int exit_check(char *input, char *COMM)
{
	int num1, num2, len, code;
	char *comp = "exit", *arr;

	num2 = code = 0, len = str_len(input);
	for (num1 = 0; num1 < 4; num1++)
	{
		if (comp[num1] != input[num1])
			return (0);
	}
	if (input[4] != '\n' && input[4] != ' ')
		return (0);

	if (len > 5)
	{
		arr = malloc(len - 5);
		for (num1 = 5; num1 < len - 1; num1++)
		{
			if (input[num1] >= '0' && input[num1] < '9')
			{
				arr[num2] = input[num1];
				num2++;
			}
			else
			{
				exit_err(COMM, input);
				free(arr);
				exitcode = 2;
				return (-1);
			}
		}
		arr[num2] = '\0';
		code = _atoi(arr);
		free(code);
	}
	free(input);
	exit(code);
}
