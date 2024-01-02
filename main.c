#include "monty.h"

int main(int argc, char * argv[])
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
	



void push(stack_t **head, int n)
{
	int line_num;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*Add data in new node*/
	new_node->n = n;

	/*Set next to point to head*/
	new_node->next = *head;
	/*Set prev pointer to NULL*/
	new_node->prev = NULL;

	/*If list is not empty, set prev to the curent node head*/
	if ((*head) != NULL)
		(*head)->prev = new_node;

	*head = new_node;


int pall()
