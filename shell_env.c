#include "shell.h"

/**
 * get_env - a function that prints to STDOUT the shell
 * environamental variables
 * @env: the array of the environment variable
 * Return: Nothing
 */

void get_env(char **env)
{
	int num;

	for (num = 0; env[num] != NULL; num++)
	{
		write(1, env[num], str_len(env[num]));
		write(1, "\n", 1);
	}
}


/**
 * path_array - a function that makes an array of PATH
 * @env: the shell environament of the user
 * Return: the PATH array in strings
 */
char **path_array(char **env)
{
	unsigned int num1, num2, counter;
	int check;
	char *tok1, *tok2, path, **arr;

	num1 = num2 = check = 0;
	while (env[num1] != NULL)
	{
		check = str_cmp(env[num1], "PATH");
		if (check == 0)
		{
			path = str_dup(env[num1]);
			counter = path_counter(path);
			tok1 = str_tok(path, "=");
			tok2 = str_tok(NULL, "=");
			arr = malloc(sizeof(char *) + counter);
			if (arr == NULL)
				return (NULL);
			if (tok[num1] == ':')
			{
				arr[num2] = str_dup("./");
				num2++;
				tok2 = str_tok(token, ":");
				tok2 = str_tok(NULL, ":");
			}
			else
				tok2 = str_tok(token, ":");

			while (num2 < counter)
			{
				arr[num2] = str_dup(tok2);
				num2++;
				tok2 = str_tok(NULL, ":");
			}
		}
		num1++;
	}
	arr[counter] = NULL;
	free(path);

	return (arr);
}


/**
 * path_counter - a function that that gets the number of directories
 * in a user's PATH
 * @path: the user shell PATH
 * Return: the total directories
 */
int path_counter(char *path)
{
	int counter, num;

	counter = num = 0;
	while (path[num] != '\0')
	{
		if (path[num] == '=' || path[num] == ':')
			counter++;
		num++;
	}

	return (counter);
}


/**
 * get_path - a function that gets a command's PATH
 * @arr: the directories as arrays
 * @command: the user input command
 * Return: the PATH otherwise NULL
 */
char *get_path(char **arr, char *command)
{
	int num1, num2, file_exist, file_exec, len_dir, len_comm, sum;
	char *path;

	file_exist = file_exec = 0;
	for (num1 = 0; arr[num1] != NULL; num1++)
	{
		len_dir = str_len(arr[num1]);
		len_comm = str_len(command);
		sum = len_dir + len_comm;
		path = malloc(sum + 2);
		if (path == NULL)
		{
			free_arr(arr);
			return (NULL);
		}

		for (num2 = 0; num2 < len_dir; num2++)
			path[num2] = arr[num1][num2];

		path[num2] = '/';
		for (num2 = 0; num2 < len_comm; num2++)
			path[len_dir + num2 + 1] = command[num2];

		path[sum + 1] = '\0';
		file_exist = access(path, F_OK);
		file_exec = access(path, X_OK);
		if (file_exist == 0)
		{
			if (file_exec == 0)
				return (path);

			free(path);
			return ("access denied");
		}
		free(path);
	}
	return (NULL);
}
