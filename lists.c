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

/**
* free_stack - function that frees a doubly linked list
* @top: top pointer to the stack
*
* Return: nothing
*/
void free_stack(stack_t *top)
{
	stack_t *temp;

	temp = top;
	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}

/**
* _stack - function that prints the top
* @top: top of stack
* @line_num: line count
*
* Return: nothing
*/
void _stack(stack_t **top, unsigned int line_num)
{
	(void)top;
	(void)line_num;
	arg.linenum = 0;
}
#include "monty.h"

/**
* _queue - function that prints the top of the queue
* @top: top of queue
* @linenum: line count
*
* Return: nothing
*/
void _queue(stack_t **top, unsigned int linenum)
{
	(void)top;
	(void)linenum;
	arg.linenum = 1;
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
