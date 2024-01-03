#include "monty.h"

/**
 * execute_opcode - execute code contained in .m files
 * @stack: stack structure
 * @func_array: function array
 * @line_number: line number
 * Return: void
 */
void execute_opcode(instruction_t func_array[],
					stack_t **stack, unsigned int line_number)
{
	char *argument;
	char *opcode;

	if (strcmp(opcode, "push") == 0)
	{
		/*Call the push function with the stack and argument*/
		push(stack, atoi(argument));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		/*Call the pall function with the stack and line_number*/
		pall(stack, line_number);
	}
	/*Add more else if conditions for other opcodes...*/
	else
	{
		/*Handle unknown opcode*/
		fprintf(stderr, "Error: Unknown opcode \"%s\" at line %u\n", opcode, line_number);
		exit(EXIT_FAILURE);
	}
}
