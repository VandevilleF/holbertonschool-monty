#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: stack structure
 * @line_number: line number
 * Return: 0 SUCCESS
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *new_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;

	pop(stack, line_number);
	pop(stack, line_number);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = result;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
