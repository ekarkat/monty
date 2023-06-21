#include "main.h"

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

void printtok()
{
	printf("%s\n", tokens[0]);
}

void free_tokens()
{
	int i = 0;
	while(tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
}

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