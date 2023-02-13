# Simple Shell Team Project
This is an ALX Project on Shell. We are tasked to come up with our own version of simple shell

## Flowchat ##
![](c_simple_shell_flow_chart.jpeg)


## Project Requirements
* C language
* Shell
* Betty Linter

## General requirements for the Project
* All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Shell should not have any memory leaks
* No more than 5 functions per file
* All header files should be include guarded
* Write a README with the description of the project

## Description
**hsh** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

How hsh Works
* Welcomes a shell user with his username!
* Prints a prompt and waits for a command from the user
* Creates a child process in which the command is checked
* Checks for built-ins, aliases in the PATH, and local executable programs
* The child process is replaced by the command, which accepts arguments
* When the command is done, the program returns to the parent process and prints the prompt
* The program is ready to receive a new command
* To exit: press Ctrl-D or enter "exit" (with or without a status)
* Works also in non interactive mode
