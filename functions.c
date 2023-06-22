#include "monty.h"
/**
 * push - the push function
 * @stack : the stack
 * @n : line lunber
*/
void push(stack_t **stack, unsigned int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);
	}
	if (mobe.token[1] == NULL || check_int(mobe.token[1]) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		free_lt();
		free_fs();
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(mobe.token[1]);
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	while ((temp)->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

/**
 * pall - the push function
 * @stack : the stack
 * @n : line lunber
*/

void pall(stack_t **stack, unsigned int n __attribute__((unused)))
{
	stack_t *head = *stack;

	while (head->next != NULL)
	{
		head = head->next;
	}

	while (head != NULL)
	{
		printf("%d\n", (head)->n);
		head = head->prev;
	}
}
