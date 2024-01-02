#include "monty.h"

void interpret_file(const char *filename, call *func_array,
					unsigned int line_number)
{
	unsigned int line_number = 0;
	int i = 0;

	FILE *file = fopen(filename, "r");
	if (!file)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char line[1024]; /*Adjust the buffer size as needed*/
	stack_t *stack = NULL;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		/*Remove trailing newline characters*/
		size_t len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		/*Tokenize the line to extract func_array and argument*/
		char *func_array = strtok(line, " ");
		char *argument = strtok(NULL, " ");

		/*Find the corresponding function in func_array and execute*/
		while (func_array[i].func_array != NULL)
		{
			if (strcmp(func_array, func_array[i].func_array) == 0)
			{
				func_array[i].f(&stack, line_number);
				break;
			}
			i++;
		}

		/*Handle unknown func_array*/
		if (func_array[i].func_array == NULL)
		{
			fprintf(stderr, "Error: Unknown func_array \"%s\" at line %u\n", func_array, line_number);
			exit(EXIT_FAILURE);
		}
	}

	// Close the file and free any allocated memory
	fclose(file);
	// Add code to free memory associated with the stack
}
