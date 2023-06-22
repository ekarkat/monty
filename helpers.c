#include "monty.h"
/**
 * check_empty - check if a line is empty
 * @line : ligne
 * Return: return 0 or 1
*/
int check_empty(char *line)
{
	int i = 0;
	int ck = 0;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			ck = 1;
			break;
		}
		i++;
	}
	return (ck);
}



/**
 * check_int - check if a string is consist of integers only
 * @str: the string
 * Return: return 0 or 1
*/
int check_int(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);

}

/**
 * free_list - add node at the end
 * @head : the head of the list
*/

void free_list(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (temp != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
