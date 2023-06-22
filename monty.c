#include "monty.h"
#include <fcntl.h>

/**
 * main - main function
 * @argc : argc
 * @argv : argv
 * Return: return error
*/

int main(int argc __attribute__((unused)), char **argv)
{
	FILE *file = fopen(argv[1], "r");
	size_t len = 1000;
	bool state = true;
	int line_number = 1;
	stack_t *stack = NULL;

	while (state)
	{
		char *line = malloc(1024);
		ssize_t tst = getline(&line, &len, file);

		if (tst == -1)
		{
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
