#include "monty.h"

/**
 * tokenize - toknize input
 * @input : the input
 * @delimiter : the delimiter
 * Return: return
*/
char **tokenize(char *input, char *delimiter)
{
	char **tokins;

	tokins = malloc(100);
	tokins[0] = strtok(input, delimiter);
	tokins[1] = strtok(NULL, delimiter);
	return (tokins);
}
