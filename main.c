#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Argument count
 * @argv: Argument values
 * Return: 0 for success, EXIT_FAILURE for failure
 */
int main(int argc, char *argv[])
{
	/* Array of function pointers and corresponding format specifiers */
	call func_array[] = {
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

	if (argv[1] == -1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	char *filename = argv[1];
	/* Open the file and start interpreting */
	interpret_file(argv[1], func_array);

	return (EXIT_SUCCESS); /*Successful execution*/
}
