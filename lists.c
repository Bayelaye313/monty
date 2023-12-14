#include "monty.h"

/**
 * addnode - adds a new node to the top of the stack
 * @top: double pointer to the top of the stack
 * @n: new value to be added
 */
void addnode(stack_t **top, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *top;

	if (*top != NULL)
		(*top)->prev = new_node;

	*top = new_node;
}

/**
 * free_stack - frees a doubly linked list
 * @top: pointer to the top of the stack
 */
void free_stack(stack_t *top)
{
	while (top != NULL)
	{
		stack_t *temp = top;
		top = top->next;
		free(temp);
	}
}

/**
 * _stack - sets the data structure to stack (LIFO)
 * @top: double pointer to the top of the stack
 * @linenum: line number of the opcode in the Monty file
 */
void _stack(stack_t **top, unsigned int linenum)
{
	(void)top;
	(void)linenum;
	arg.linenum = 0;
}

/**
 * _queue - sets the data structure to queue (FIFO)
 * @top: double pointer to the top of the stack
 * @linenum: line number of the opcode in the Monty file
 */
void _queue(stack_t **top, unsigned int linenum)
{
	(void)top;
	(void)linenum;
	arg.linenum = 1;
}

/**
 * addqueue - adds a new node to the end of the queue
 * @top: double pointer to the top of the queue
 * @n: new value to be added
 */
void addqueue(stack_t **top, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*top == NULL)
	{
		*top = new_node;
		new_node->prev = NULL;
	}
	else
	{
		stack_t *temp = *top;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new_node;
		new_node->prev = temp;
	}
}
