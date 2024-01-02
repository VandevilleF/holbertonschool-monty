#include "monty.h"

/**
 * push - push an integer to a stack
 * @n: integer value
 * @head: head of the structure
 * Return: void
 */
void push(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*Add data in new node*/
	new_node->n = n;
	/*Set next to point to head*/
	new_node->next = *head;
	/*Set prev pointer to NULL*/
	new_node->prev = NULL;

	/*If list is not empty, set prev to the curent node head*/
	if ((*head) != NULL)
		(*head)->prev = new_node;

	*head = new_node;
}

/**
 * pall - prints the integers contained in the stack
 * @line_number: line number to report errors
 * @stack: the stack where to print from
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "Error: Stack is NULL at line %u\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (new_node != NULL)
		{
			printf("%d\n", new_node->n);
			new_node = new_node->next;
		}
	}
}
