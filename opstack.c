#include "monty.h"

/**
 * is_integer - checks if a string represents a valid integer
 * @str: input string to check
 * Return: 1 if it's a valid integer, 0 otherwise
 */
int is_integer(const char *str)
{
	int m = 0, flag = 0;

	if (!str)
		return (0);

	if (str[0] == '-')
		m++;

	for (; str[m] != '\0'; m++)
	{
		if (str[m] > '9' || str[m] < '0')
			flag = 1;
	}

	return (!flag);
}

/**
 * push_error_exit - handles errors during push operation and exits
 * @top: double top pointer to the stack
 * @linenum: line count
 *
 * This func is responsible for printing the error msge, closing the script,
 * freeing the content, freeing the stack, and exiting with FAILURE status.
 */
void push_error_exit(stack_t **top, unsigned int linenum)
{
	fprintf(stderr, "L%d: usage: push integer\n", linenum);
	fclose(arg.script);
	free(arg.content);
	free_stack(*top);
	exit(EXIT_FAILURE);
}

/**
 * _push - function that adds node to the stack
 * @top: double top pointer to the stack
 * @linenum: line count
 * This is responsible for parsing the token and push the integer onto stack.
 */
void _push(stack_t **top, unsigned int linenum)
{
	int value;

	if (!arg.tok || !is_integer(arg.tok))
		push_error_exit(top, linenum);

	value = atoi(arg.tok);
	if (arg.linenum == 0)
		addnode(top, value);
	else
		addqueue(top, value);
}

/**
* _pop - function that prints the top of the stack
* @top: double top pointer to the stack
* @line_num: line count
*
* Return: nothing
*/
void _pop(stack_t **top, unsigned int line_num)
{
	stack_t *run;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	run = *top;
	*top = run->next;
	free(run);
}

/**
* _swap - function that swaps the top two elements of the stack
* @top: top of stack
* @line_num: line count
*
* Return: nothing
*/
void _swap(stack_t **top, unsigned int line_num)
{
	stack_t *h;
	int temp;

	h = *top;
	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
