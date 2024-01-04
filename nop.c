#include "monty.h"

/**
 * nop - doesn't do anything
 * @stack: stack structure
 * @line_number: line counter
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) **stack;
	(void) line_number;
}
