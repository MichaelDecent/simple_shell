# include "shell.h"


/**
 * free_arr - a function that frees a memory
 * @arr: the pointer to the arry
 * Return: Nothing
 */
void free_arr(char **arr)
{
	size_t num;

	for (num = 0; arr[num] != '\0'; num++)
	{
		free(arr);
	}
	free(arr);
}
