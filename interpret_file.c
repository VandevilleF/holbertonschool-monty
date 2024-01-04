#include "monty.h"

/**
 * interpret_file - file interpreter for monty
 * @filename: name of the file to be read
 * @func_array: array of functions
 * @line_number: line counter
 * @stack: stack structure
 * Return: 0 SUCCESS
 */
void interpret_file(const char *filename, instruction_t func_array[],
					unsigned int line_number, stack_t **stack)
{
	int i = 0;
	char line[1024];
	char *instruct;
	FILE *file = fopen(filename, "r");

	line_number = 0;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		instruct = strtok(line, " \n\t");
		if (instruct != NULL)
		{
			while (func_array[i].opcode != NULL)
			{
				if (strcmp(func_array[i].opcode, instruct) == 0)
				{
					func_array[i].f(stack, line_number);
					break;
				}
				i++;
			}
			if (func_array[i].opcode == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruct);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
			i = 0;
		}
	}
	free_stack(stack);
	fclose(file);
}
