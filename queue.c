#include "monty.h"

/**
* f_queue - function that prints the top of the queue
* @top: top of queue
* @counter: line count
*
* Return: nothing
*/
void f_queue(stack_t **top, unsigned int counter)
{
	(void)top;
	(void)counter;
	bus.lifi = 1;
}

/**
* addqueue - function that add node to the tail the queue
* @n: new value
* @top: top of the queue
*
* Return: nothing
*/
void addqueue(stack_t **top, int n)
{
	stack_t *new_node, *temp;

	temp = *top;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*top = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
