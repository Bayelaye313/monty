#include "monty.h"

/**
* _rotr - function that rotates the stack to the bottom
* @top: stack top of the stack
* @counter: line count
*
* Return: nothing
*/
void _rotr(stack_t **top, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *top;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*top)->prev = copy;
	(*top) = copy;
}
