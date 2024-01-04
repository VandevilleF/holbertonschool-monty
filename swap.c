#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack where the print from
 * @line_number: count of line number for error message
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->prev = temp;
		(*stack)->next = temp->next;
		temp->next = *stack;
		temp->prev = NULL;
		*stack = temp;
	}
}
