#include "monty.h"

/**
 * check_empty - check if a line is empty
 * @line : ligne
 * Return: return 0 or 1
*/
int check_empty(char *line)
{
	int i = 0;
	int ck = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			ck = 1;
			break;
		}
		i++;
	}
	return (ck);
}

/**
 * check_int - check if a string is consist of integers only
 * @str: the string
 * Return: return 0 or 1
*/
int check_int(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);

}
/**
 * free_lt - free line and token
*/

void free_lt(void)
{
	if (mobe.lin != NULL)
	{
		free(mobe.lin);
	}
	if (mobe.token != NULL)
	{
		free(mobe.token);
	}
}

/**
 * free_fs - free file and stack
*/

void free_fs(void)
{
	if (mobe.fil != NULL)
	{
		fclose(mobe.fil);
	}
	if (mobe.stak != NULL)
	{
		free_stack(mobe.stak);
	}
}

/**
 * fill_list - fill a alist
 * @lin : line
 * @token : token
 * @stak : the stack
 * @fil : the file
*/

void fill_list(char *lin, char **token, FILE *fil, stack_t *stak)
{
	(void)lin;
	(void)token;
	(void)fil;
	(void)stak;
	mobe.fil = fil;
	mobe.lin = lin;
	mobe.stak = stak;
	mobe.token = token;
}

