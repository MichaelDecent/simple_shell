#include "shell.h"

/**
 * exit_err - a function that prints to STDERR if user input
 * an wrong exit code
 * @COMM: the command name
 * @input: the command
 */

void exit_err(char *COMM, char *input);
{
	char *token;

	token = str_tok(input, "\n ");
	token = str_tok(NULL, "\n ");

	write(2, COMM, str_len(COMM));
	write(2, ": ", 2);
	print_number(errorcount);
	write(2, ": exit: Illegal number: ", 24);
	write(2, token, _strlen(token));
	write(2, "\n", 1);
}


/*
 * command_not_found_err - a function that prints to STDERR if
 * user command is not found
 * @COMM: the command name
 * @message: the error
 */
void command_not_found_err(char *COMM, char *message);
{
	write(2, COMM, _strlen(COMM));
	write(2, ": ", 2);
	print_number(errorcount);
	write(2, ": ", 2);
	write(2, message, str_len(message));
	write(2, ": not found\n", 13);

	exitcode = 127;
}


/**
 * command_execute_err - a function that prints to STDERR if
 * user command cannot execute
 * @COMM: the command name
 * @message: the error
 */
void command_execute_err(__attribute__((unused))char *COMM, char *message);
{
	perror(message);
	exitcode = 2;
}


/**
 * privilege_err - a function that prints to STDERR if
 * user does have enough privilege
 * @COMM: the command name
 * @message: the error
 */
void privilege_err(char *COMM, char *message);
{
	write(2, COMM, str_len(COMM));
	write(2, ": ", 2);
	write(2, message, str_len(message));
	write(2, ": Permission denied\n", 20);
}
