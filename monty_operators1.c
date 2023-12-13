#include "monty.h"

/**
* _push - function that adds node to the stack
* @top: double top pointer to the stack
* @linenum: line count
*
* Return: nothing
*/
void _push(stack_t **top, unsigned int linenum)
{
	int i, m = 0, flag = 0;

	if (arg.tok)
	{
		if (arg.tok[0] == '-')
			m++;
		for (; arg.tok[m] != '\0'; m++)
		{
			if (arg.tok[m] > 57 || arg.tok[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", linenum);
			fclose(arg.script);
			free(arg.content);
			free_stack(*top);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", linenum);
		fclose(arg.script);
		free(arg.content);
		free_stack(*top);
		exit(EXIT_FAILURE); }
	i = atoi(arg.tok);
	if (arg.linenum == 0)
		addnode(top, i);
	else
		addqueue(top, i);
}
