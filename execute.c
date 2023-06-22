#include "monty.h"

char **tokens = NULL;

/**
 * get_op - function pointer
 * @opcode : the opening code
 * Return: function
*/
void (*get_op(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * execute - execute line
 * @stack : the struct stack
 * @line: the line
 * @line_number : the line number
 * Return: return error
*/

int execute(stack_t **stack, char *line, int line_number)
{
	void (*op_func)(stack_t**, unsigned int);

	tokens = tokenize(line, " \n\t");

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	op_func = get_op(tokens[0]);
	if (op_func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
		exit(EXIT_FAILURE);
		return (0);
	}
	op_func(stack, line_number);
	return (0);
}
