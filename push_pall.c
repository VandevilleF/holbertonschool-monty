#include "monty.h"

/**
 * push_pall - pushes integers to a stack and prints them
 * Return: 0 SUCCESS
 */

/*Function to implement the push opcode*/
function push(stack, argument, line_number):
	if argument is not provided or not an integer:
		print_error_and_exit("L<line_number>: usage: push integer")
	else:
		integer_value = convert_to_integer(argument)
		push_integer_onto_stack(stack, integer_value)

/*Function to implement the pall opcode*/
function pall(stack):
	if stack is empty:
		return  # Do nothing if the stack is empty
	else:
		iterate_over_stack_from_top(stack):
			print(current_element)

/*Function to print an error message and exit*/
function print_error_and_exit(message):
	print("Error: " + message)
	exit(EXIT_FAILURE)

/*Function to convert a string to an integer*/
function convert_to_integer(string):
	return atoi(string)

/*Function to push an integer onto the stack*/
function push_integer_onto_stack(stack, integer_value):
	new_node = create_new_node_with_value(integer_value)
	add_node_to_stack(stack, new_node)

/*Function to create a new node with a given value*/
function create_new_node_with_value(value):
	new_node = allocate_memory_for_node()
	new_node.n = value
	new_node.prev = NULL
	new_node.next = NULL
	return new_node

/*Function to add a node to the top of the stack*/
function add_node_to_stack(stack, new_node):
	if stack is empty:
		stack = new_node
	else:
		new_node.next = stack
		stack.prev = new_node
		stack = new_node
