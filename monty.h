#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* global */
extern char **tokens;



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct ltfs_s - line tokens file stack
 * @lin: the input line
 * @token: the tokens
 * @fil : the file
 * @stak : the stack
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct ltfs_s
{
	char *lin;
	char **token;
	FILE *fil;
	stack_t *stak;
} ltfs_t;

extern ltfs_t mobe;

void push(stack_t **stack, unsigned int n);
void pall(stack_t **stack, unsigned int n);
int check_empty(char *line);
int execute(stack_t **stack, char *line, int line_number);
char **tokenize(char *input, char *delimiter);
void free_tokens(void);
int check_int(char *str);
void free_lt(void);
void free_fs(void);
void fill_list(char *lin, char **token, FILE *fil, stack_t *stak);
void free_stack(stack_t *head);
void pint(stack_t **stack, unsigned int counter);
void pop(stack_t **stack, unsigned int counter);
void swap(stack_t **stack, unsigned int counter);
void add(stack_t **stack, unsigned int counter);


#endif
