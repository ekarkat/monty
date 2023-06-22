#include "main.h"
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
 * printtok - print a token
*/

void printtok(void)
{
	printf("%s\n", tokens[0]);
}

/**
 * free_tokens - free a token
*/
void free_tokens(void)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
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
