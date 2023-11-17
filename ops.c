#include "monty.h"

/**
 * op_push - add element on top of stack
 * @stack: pointer to a pointer to the doubly linked list
 * @line_num: line where there is an error
 * @n: op_code
 */

void op_push(stack_t **stack, char *n, unsigned int line_num)
{
	stack_t *new = NULL;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i]; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (n[i] < 48 || n[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * op_pall - print stack's elements
 * @line_num: will not be used , we usse attribute not void
 * @stack: pointer to the head of the doubly linked list
 */

void op_pall(stack_t **stack, unsigned int __attribute__((unused)) line_num)
{
	stack_t *curr = *stack;

	if (stack == NULL || *stack == NULL)
		return;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * op_nop - do nothing
 * @stack: pointer to to pointer to the doubly linked list
 * @line_num: number of lines in the file
 */

void op_nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
 * op_pint - print the int at the top of stack
 * @stack: double pointer th the head
 * @line_number: number of lines
 * Return: void
 */

void op_pint(stack_t **stack, unsigned int __attribute__((unused)) line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the last inserted element
 * @line_number: number of lines  in the file
 * @stack: pointer to the pointer to the head
 * Return: void
 */

void op_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *to_the_end;

	if (stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	else if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		to_the_end = *stack;
		*stack = (*stack)->next;
		free(to_the_end);
	}
}
