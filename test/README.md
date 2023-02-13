# C - Simple Shell

## Compilation ##
Your shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


## Testing ##
Your shell should work like this in interactive mode:

~~~~
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
~~~~

But also in non-interactive mode:

~~~~
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
~~~~

## Checks ##
The Checker will be released at the end of the project (1-2 days before the deadline). We strongly encourage the entire class to work together to create a suite of checks covering both regular tests and edge cases for each task. See task 8. Test suite.

