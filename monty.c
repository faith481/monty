#include "monty.h"


/**
 * find_opcode - find operation code
 * @stack: stack pointer
 * @opcode: user input opcode
 * @line_num: line number
 * Return: On success 1 or stderr
 */

int find_opcode(stack_t **stack, char *opcode, int line_num)
{
	instruction_t opcodes[] = {
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"pint", op_pint},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_num);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	exit(EXIT_FAILURE);
}


/**
 * main - main function
 * @argc: number of command line arguments
 * @argv: list of command line arguments
 * Return: EXIT_SUCCESS if no errors or EXIT_FAILURE
 */

int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *mofi;
	char *buf = NULL, *opcode, *n;
	size_t lol = 0;
	int line_num = 0;
	stack_t *stack = NULL, *curr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	mofi = fopen(argv[1], "r");
	if (mofi == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(1);
	}
	while ((getline(&buf, &lol, mofi)) != -1)
	{
		line_num++;
		opcode = strtok(buf, DELIMITER);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (!strcmp(opcode, "nop"))
			continue;
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DELIMITER);
			op_push(&stack, n, line_num);
		}
		else
			find_opcode(&stack, opcode, line_num);
	}
	fclose(mofi);
	free(buf);
	while (stack != NULL)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}
	return (0);
}
