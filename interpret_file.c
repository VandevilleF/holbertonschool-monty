#include "monty.h"

void interpret_file(const char *filename, instruction_t func_array[],
					unsigned int line_number, stack_t **stack)
{
	int i = 0;
	char line[1024]; /*Adjust the buffer size as needed*/

	line_number = 0;
	/*stack = NULL;*/
	char *instruct;

	FILE *file = fopen(filename, "r");

	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		instruct = strtok(line, " \n\t");
		while (func_array[i].opcode != NULL)
		{
			if (strcmp(func_array[i].opcode, instruct) == 0)
			{
				func_array[i].f(stack, line_number);
				break;
			}
			i++;
		}
		/*Handle unknown func_array*/
		if (func_array[i].opcode == NULL)
		{
			fprintf(stderr, "Error: Unknown func_array");
			exit(EXIT_FAILURE);
		}
		i = 0;
	}
	free_stack(stack);
	fclose(file);
}
