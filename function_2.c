#include "monty.h"
/**
 * swap - adds the top two elements of the stack.
 * @stack: stack stack
 * @counter: line_number
 * Return: no return
*/
void swap(stack_t **stack, unsigned int counter)
{
	stack_t *head;
	stack_t *last = *stack;
	int n;
	int len = 0;

	head = *stack;
	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);
	}

	while (last->next != NULL)
		last = last->next;
	n = last->n;
	last->n = last->prev->n;
	last->prev->n = n;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void add(stack_t **stack, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);
	}
	while (last->next != NULL)
		last = last->next;
	sum = last->n + last->prev->n;
	last->prev->n = sum;
	last->prev->next = NULL;
	free(last);
}

/**
  *nop - nothing
  *@stack: stack head
  *@counter: line_number
  *Return: no return
 */
void nop(stack_t **stack, unsigned int counter)
{
	(void)counter;
	(void)stack;
}

/**
 * sub - adds the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void sub(stack_t **stack, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);
	}
	while (last->next != NULL)
		last = last->next;
	sum = (last->prev->n) - (last->n);
	last->prev->n = sum;
	last->prev->next = NULL;
	free(last);
}

/**
 * div - adds the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void m_div(stack_t **stack, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		free_lt();
		free_fs();
		exit(EXIT_FAILURE);
	}
	while (last->next != NULL)
		last = last->next;
	sum = last->prev->n / ((last->n));
	last->prev->n = sum;
	last->prev->next = NULL;
	free(last);
}
