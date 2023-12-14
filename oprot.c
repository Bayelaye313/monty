#include "monty.h"

/**
 * _rotl - rotates the stack to the top
 * @top: double pointer to the top of the stack
 * @linenum: line number of the opcode in the Monty file
 *
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */
void _rotl(stack_t **top, __attribute__((unused)) unsigned int linenum)
{
	if (*top != NULL && (*top)->next != NULL)
	{
		stack_t *new_top = (*top)->next;
		stack_t *current = *top;

		while (current->next != NULL)
			current = current->next;

		current->next = *top;
		(*top)->prev = current;
		(*top)->next = NULL;
		new_top->prev = NULL;
		*top = new_top;
	}
}

/**
 * _rotr - rotates the stack to the bottom
 * @top: double pointer to the top of the stack
 * @linenum: line number of the opcode in the Monty file
 *
 * Description: The last elem of the stack becomes the top elem of the stack.
 */
void _rotr(stack_t **top, __attribute__((unused)) unsigned int linenum)
{
	stack_t *new_top;

	new_top = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (new_top->next)
	{
		new_top = new_top->next;
	}
	new_top->next = *top;
	new_top->prev->next = NULL;
	new_top->prev = NULL;
	(*top)->prev = new_top;
	(*top) = new_top;
}
