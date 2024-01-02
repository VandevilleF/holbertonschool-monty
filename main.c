#include "monty.h"

/**
 * main - check the code
 * @argc: argument count
 * @argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
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
}
