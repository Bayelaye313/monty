#include "monty.h"

/**
* _rotl- function that rotates the stack to the top
* @top: top of the stack
* @counter: line count
*
* Return: nothing
*/
void _rotl(stack_t **top,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *top, *aux;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	aux = (*top)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *top;
	(*top)->next = NULL;
	(*top)->prev = tmp;
	(*top) = aux;
}
