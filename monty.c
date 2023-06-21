#include "main.h"


int main(int argc __attribute__((unused)), char **argv __attribute__((unused))) 
{
	char *line = NULL;
	size_t len = 0;
	bool state = true;
	int line_number = 1;
	stack_t *stack = NULL;

	while (state)
	{
		_getline(&line, &len, stdin);
		if (check_empty(line) == 0)
		{
			line_number++;
			continue;
		}
		execute(&stack, line, line_number);		
		line_number++;
		free(line);
		free_tokens();
	}
	
	return 0;
}
