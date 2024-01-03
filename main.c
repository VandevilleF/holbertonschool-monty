#include "monty.h"

/**
 * main - check the code
 * @argc: argument count
 * @argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
	char *filename;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	/* Array of function pointers and corresponding format specifiers */
	instruction_t func_array[] = {
		{"push", push},
		{"pall", pall},
		/**
		*{"pint", pint},
		*{"pop", pop},
		*{"swap", swap},
		*{"add", add},
		*{"nop", nop},
		*/
		{NULL, NULL},
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	interpret_file(argv[1], func_array, line_number, &stack);
	execute_opcode(func_array, &stack, line_number);

	return (EXIT_SUCCESS); /*Successful execution*/
}
