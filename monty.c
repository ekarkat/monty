#include "main.h"
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
	char *line = NULL;
	size_t len = 0;
	bool state = true;
	int line_number = 1;
	stack_t *stack = NULL;

	while (state)
	{
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
