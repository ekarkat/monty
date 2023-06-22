#include "monty.h"

ltfs_t mobe = {NULL, NULL, NULL, NULL};

/**
 * main - main function
 * @argc : argc
 * @argv : argv
 * Return: return error
*/

int main(int argc __attribute__((unused)), char **argv)
{
	char *line;
	FILE *file = fopen(argv[1], "r");
	size_t len = 0;
	bool state = true;
	int line_number = 1;
	stack_t *stack = NULL;
	ssize_t tst;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (state)
	{
		line = NULL;
		tst = getline(&line, &len, file);
		fill_list(line, NULL, file, stack);
		if (tst == -1)
		{
			free_fs();
			free_lt();
			exit(EXIT_SUCCESS);
		}
		if (check_empty(line) == 0)
		{
			line_number++;
			continue;
		}
		execute(&stack, line, line_number);
		line_number++;
	}
	return (0);
}
