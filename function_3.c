#include "monty.h"

/**
 * mul - adds the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void mul(stack_t **stack, unsigned int counter)
{
	stack_t *h;
	int len = 0, sum;
	stack_t *last = *stack;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);
	}
	while (last->next != NULL)
		last = last->next;
	sum = last->prev->n * ((last->n));
	last->prev->n = sum;
	last->prev->next = NULL;
	free(last);
}

/**
 * mod - adds the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void mod(stack_t **stack, unsigned int counter)
{
	stack_t *h;
	int len = 0, sum;
	stack_t *last = *stack;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);
	}
	while (last->next != NULL)
		last = last->next;
	if (last->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);		
	}
	sum = last->prev->n % ((last->n));
	last->prev->n = sum;
	last->prev->next = NULL;
	free(last);
}

/**
 * pchar - the pint function
 * @stack : the stack
 * @counter : line lunber
*/

void pchar(stack_t **stack, unsigned int counter)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
		free_fs();
		free_lt();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;

	printf("%c\n", temp->n);
}