#include "monty.h"

void interpret_file(const char *filename, instruction_t func_array[],
					unsigned int line_number)
{
	int i = 0;
	char line[1024]; /*Adjust the buffer size as needed*/
	stack_t *stack;
	size_t len;
	char *instruct, *argument;

	FILE *file = fopen(filename, "r");

	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	stack = NULL;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		/*Remove trailing newline characters*/
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		/*Tokenize the line to extract func_array and argument*/
		instruct = strtok(line, " ");
		argument = strtok(NULL, " ");

		/*Find the corresponding function in func_array and execute*/
		while (func_array[i].opcode != NULL)
		{
			if (strcmp(func_array[i].opcode, instruct) == 0)
			{
				func_array[i].f(&stack, line_number);
				break;
			}
			i++;
		}

		/*Handle unknown func_array*/
		if (func_array[i].opcode == NULL)
		{
			fprintf(stderr, "Error: Unknown func_array \"%s\" at line %u\n", func_array, line_number);
			exit(EXIT_FAILURE);
		}
		i = 0;
	}
	free_stack(&stack);
	/*Close the file and free any allocated memory*/
	fclose(file);
	/*Add code to free memory associated with the stack*/
}
