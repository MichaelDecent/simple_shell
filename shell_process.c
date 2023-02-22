#include "shell.h"


/**
 * process_fork - a function that forks a child process while executing
 * the child while the parent wait
 * @command: the user command arrays
 * @arr: the user directory arrays
 * @env: the array of the user shell enviromental variables
 * @COMM: the name of the command
 * @input: the user input
 * Return: Nothing
 */
void process_fork(char **command, char **arr, char **env,
		char *COMM, char *input)
{
	int code, exe_status;
	pid_t pid;

	code = 0;
	pid = fork();

	if (pid == -1)
	{
		perror(COMM);
		exitcode = 1;
		_Exit(exitcode);
	}
	else if
	{
		exe_status = execve(command[0], command, env);
		if (exe_status < 0)
		{
			command_execute_err(COMM, command[0]);
			free_arr(arr);
			free_arr(command);
			free(input);
			exitcode = 126;
			_Exit(exitcode);
		}

		exitcode = 0;
		_Exit(exitcode);
	}
	exitcode = 0;
	wait(&code);
}
