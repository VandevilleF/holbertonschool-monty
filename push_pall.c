#include "monty.h"

/**
 * push - push an integer to a stack
 * @line_number: integer value
 * @head: head of the structure
 * Return: void
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;
	int data;

	arg = strtok(NULL, " \t\n");

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = atoi(arg);

	if (data != 0)
	{
		new_node = malloc(sizeof(stack_t));

		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		/*Add data in new node*/
		new_node->n = data;
		/*Set next to point to head*/
		new_node->prev = NULL;
		new_node->next = *head;
		if ((*head) != NULL)
			(*head)->prev = new_node;

		*head = new_node;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints the integers contained in the stack
 * @line_number: line number to report errors
 * @stack: the stack where to print from
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	while (new_node != NULL)
	{
		printf("%d\n", new_node->n);
		new_node = new_node->next;
	}
}
