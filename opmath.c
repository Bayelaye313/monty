#include "monty.h"

/**
 * _add - adds top of stack and second top of stack
 *
 * @top: pointer to linked list stack
 * @linenum: number of line opcode occurs on
 */
void _add(stack_t **top, unsigned int linenum)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linenum);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n += (*top)->n;
	_pop(top, linenum);
}
/**
 * _sub - subtracts top of stack and second top of stack
 *
 * @top: pointer to linked list stack
 * @linenum: number of line opcode occurs on
 */
void _sub(stack_t **top, unsigned int linenum)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linenum);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n -= (*top)->n;
	_pop(top, linenum);
}
/**
 * _mul - function that multiplies the top two elements of the stack
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * Return: nothing
 */
void _mul(stack_t **top, unsigned int linenum)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", linenum);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n *= (*top)->n;
	_pop(top, linenum);
}
/**
 * _div - function that divides the top two elements of the stack
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * Return: nothing
 */
void _div(stack_t **top, unsigned int linenum)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", linenum);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n /= (*top)->n;
	_pop(top, linenum);
}
/**
 * _mod - function that computes the remainder of the division
 * of the second top element of the stack by the top element of the stack
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * Return: nothing
 */
void _mod(stack_t **top, unsigned int linenum)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", linenum);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linenum);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n %= (*top)->n;
	_pop(top, linenum);
}
