#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack where to print from
 * @line_number: count of line number for error message
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: the stack where to print from
 * @line_number: count of line number for error message
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;

			if (*stack != NULL)
				(*stack)->prev = NULL;
		free(temp);
	}
}
