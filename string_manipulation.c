#include "shell.h"

/**
 * _putchar - a function that prints a signle character to STDOUT
 * @c: the character to print
 * Return: 1 as Success otherwise -1 as Failure
 */
int _putchar(char c);
{
	return (write(1, &c, 1));
}


/**
 * str_len - a functiomn that returns the length of a string
 * @s: the string to get the length
 * Return: the length of the string
 */
int str_len(char *s)
{
	int len;

	for (len = 0; str[len] != '\0', len++)
		continue;

	return (len);
}


/**
 * str_dup - a function that copies a string to a new memory space
 * @s: the string to copy
 * Return: the pointer to the newly allocated memory space
 */
char *str_dup(char *s)
{
	int num;
	char *str_arr;

	if (s == NULL)
		return (NULL);

	str_arr = malloc(str_len(s) + 1);
	if (str_arr == NULL)
		return (NULL);

	for (num = 0; num < str_len(s); num++)
		str_arr[num] = s[num];

	str_arr[num] = '\0';

	return (str_arr);
}


/**
 * str_cmp - a function that compares two string
 * @s1: the first string to compare
 * @s2: the second string to compare
 * Return: the difference between the first and second string
 * otherwise 0 as Equality
 */
int str_cmp(char *s1, char *s2)
{
	int num;

	for (num = 0; s1[num] != '\0' && s2[num] != '\0'; num++)
	{
		if (s1[num] < s2[num])
			return (s1[num] - s2[num]);

		else if (s1[num] > s2[num])
			return (s1[num] - s2[num]);
	}

	return (0);
}
