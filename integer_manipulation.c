#include "shell.c"


/**
 * atoi_ - a function that converts a string to integer
 * @str: the input string to convert
 * Return: the converted integer
 */
int atoi_(char *str)
{
	unsigned int counter, num, i_num;

	counter = num = i_num = 0;

	while (!(str[i_num] >= '0' && str[i_num] <= '9') && str[i_num] != '\0')
	{
		if (str[i_num] == '-')
			counter++;
		i_num++;
	}

	while (str[i_num] >= '0' && str[i_num] <= '9')
	{
		num = (str[i_num] - '0') + (num * 10);
		i_num++;
	}

	if (counter % 2 != 0)
		num = -num;

	return (num);
}


/**
 * print_num - a function that prints an integer to STDOUT
 * @num: the integer
 * Return: Nothing
 */
void print_num(int num)
{
	int int_num, dig, sum, div = 1000000000;
	unsigned int un_num;

	int_num = num, sum = 0;

	while (div > 1)
	{
		dig = (un_num / div) % 10;
		sum += dig;
		if (sum != 0)
			_putchar(dig + '0');
		div /= 10;
	}

	int_num = num % 10;
	_putcahr(int_num + '0');
}
