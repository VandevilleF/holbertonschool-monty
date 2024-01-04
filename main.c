#include "monty.h"

/**
 * main - check the code
 * @argc: argument count
 * @argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	/* Array of function pointers and corresponding format specifiers */
	instruction_t func_array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{NULL, NULL},
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	interpret_file(argv[1], func_array, line_number, &stack);
	free_stack(&stack);

	return (EXIT_SUCCESS); /*Successful execution*/
}
