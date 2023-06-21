#include "main.h"

/*
*Important notice : the buffer used for _getline argument
*must be initialized to NULL or allocated, otherwise it will give an error
*/

/**
 * insertstring - concat dst and str
 * @dst: destination
 * @str: string to add
 * Return: allocated memory to new dst
*/

char *insertstring(char **dst, char *str)
{
	if (*dst == NULL && str == NULL)
		return (NULL);
	if (*dst == NULL)
	{
		int i = 0;
		*dst = malloc(strlen(str));
	
		while (str[i] != 0)
		{
			(*dst)[i] = str[i];
			i++;
		}
		return (*dst);
	}
	else
	{
		int i = 0, j = 0;
		int ln, lif;
		char *dstcopy = *dst;

		ln = strlen(*dst);
		lif = strlen(str);
		*dst = malloc(ln + lif - 1);

		while (j < ln)
		{
			(*dst)[j] = dstcopy[j];
			j++;
		}
		while (i <= lif)
		{
			(*dst)[ln + i] = str[i];
			i++;
		}
			free(dstcopy);

		return (*dst);
	}
}

/**
 * check - check if line contain \n
 * @line: the string
 * @n: number of characters read in (read)
 * Return: 0 if it doesnt 1 if it does
*/
int check(char **line, int n)
{
	int i = 0, j = 0;
	int kn = 0;
	char *new, *copybuff;

	while ((*line)[i] != '\0')
	{
		if ((*line)[i] == '\n')
		{
			kn = 1;
			break;
		}
		i++;
	}
	if (kn == 1)
	{
		new = malloc(i + 2);
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);			
		}
		copybuff = *line;
		if (i != 0)
		{
			while (j <= i)
			{
				new[j] = copybuff[j];
				j++;
			}
		}
		else
			new[i] = '\n';
		new[i + 1] = '\0';
		free(*line);
		*line = new;
	}
	if (kn == 0 && n < 1024)
		kn = 1;
	return (kn);
}


/**
 * _getline - prototype of getline
 * @line: the buffer to store the new line
 * @n: the number of char read
 * @fp: FILE structur
 * Return: the number of charcters read
*/
ssize_t _getline(char **line, size_t *n, FILE *fp)
{
	char *buff, *copyline, safecopy[1024];
	int i, rd, j = 0;
	int fd = fp->_fileno;

	rd = read(fd, safecopy, 1023);
	if (rd == -1)
		return (-1);
	if (rd == 0)
		return (EOF);
	safecopy[rd] = '\0';
	
	copyline = malloc(1024);
	if (copyline == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for(;j <= rd;j++)
		copyline[j] = safecopy[j];
	
	i = check(&copyline, rd);
	while (i == 0)
	{
		buff = malloc(1024);
		rd = read(fd, buff, 1023);
		buff[rd] = 0;
		copyline = insertstring(&copyline, buff);
		i = check(&copyline, rd);
		free(buff);
	}

	*line = copyline;

	*n = strlen(*line);
	return (*n);
}
