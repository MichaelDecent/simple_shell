#include "shell.h"

/**
 * splash_display - a function that displays ascii art when program starts
 * @ptr_f: pointer to .txt file that contains ascii art
 * Return: Nothing
 */

void splash_display(FILE *ptr_f)
{
	char str_read[MAX_LEN];

	while (fgets(str_read, sizeof(str_read), ptr_f != NULL))
		printf("%s", str_read);
}
