#ifndef SHEEL_H
#define SHELL_H


/* C LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/* STRING MANIPULATION */
int _putchar(char c);
int str_len(char *s);
char *str_dup(char *s);
int str_cmp(char *s1, char *s2);


#endif
