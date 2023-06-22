#include "monty.h"

/**
 * tokenize - toknize input
 * @input : the input
 * @delimiter : the delimiter
 * Return: return
*/
char **tokenize(char *input, char *delimiter)
{
	char **tokens;

	tokens = malloc(100);
	tokens[0] = strtok(input, delimiter);
	tokens[1] = strtok(NULL, delimiter);
	return (tokens);
}
