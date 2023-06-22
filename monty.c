#include "main.h"
#include <fcntl.h>
#include <stdio.h>

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
		getline(&line, &len, file);

		if (check_empty(line) == 0)
		{
			line_number++;
			continue;
		}
		execute(&stack, line, line_number);		
		line_number++;
	}
	
	return 0;
}
