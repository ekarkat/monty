#include "main.h"
char *_strdup(char *s)
{
	char *copy = NULL;
	int len;

	if (!s)
		return (NULL);

	len = strlen(s);

	copy = malloc(sizeof(char) * len + 1);

	if (!copy)
	{
		perror("malloc() failed");
		return (NULL);
	}

	strcpy(copy, s);

	/*s[len] = '\0';*/
	return (copy);
}

char **tokenize(char *input, char *delimiter)
{
	char *input_copy, *token;
	char **tokens;
	int num_tokens = 0, i = 0;

	input_copy = _strdup(input);

	if (!input_copy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, delimiter);

	while (token)
	{
		num_tokens++;
		token = strtok(NULL, delimiter);
	}
	num_tokens++;

	tokens = malloc(sizeof(char *) * num_tokens);

	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input_copy, delimiter);

	while (token)
	{
		tokens[i] = _strdup(token);

		token = strtok(NULL, delimiter);
		i++;
	}
	tokens[i] = NULL;

	free(input_copy);

	return (tokens);
}
