#include "monty.h"

/**
* addnode - function that adds node to the top stack
* @top: top of the stack
* @n: new value
*
* Return: nothing
*/
void addnode(stack_t **top, int n)
{
	stack_t *new_node, *temp;

	temp = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *top;
	new_node->prev = NULL;
	*top = new_node;
}
