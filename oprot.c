#include "monty.h"

/**
* _rotl- function that rotates the stack to the top
* @top: top of the stack
* @linenum: line count
*
* Return: nothing
*/
void _rotl(stack_t **top,  __attribute__((unused)) unsigned int linenum)
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

/**
* _rotr - function that rotates the stack to the bottom
* @top: stack top of the stack
* @linenum: line count
*
* Return: nothing
*/
void _rotr(stack_t **top, __attribute__((unused)) unsigned int linenum)
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
