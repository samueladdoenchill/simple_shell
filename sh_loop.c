#include "main.h"

/**
 * without_comment - Deletes comments from the input string.
 *
 * @in: Input string.
 * Return: Input without comments.
 */
char *without_comment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		/* Check if the character is a comment symbol '#' */
		if (in[i] == '#')
		{
			/* If '#' is the first character, free input and return NULL */
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			/* Check if the previous character is whitespace or ';' */
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}

	/* If any comment symbol was found, remove comments and terminate string */
	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Main loop of the shell.
 * @datash: Data structure containing relevant data (av, input, args).
 *
 * Return: No return value.
 */
void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		/* Display the shell prompt */
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			/* Remove comments from the input */
			input = without_comment(input);
			if (input == NULL)
				continue;

			/* Check for syntax errors */
			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}

			/* Replace variables in the input */
			input = rep_var(input, datash);

			/* Split commands and execute them */
			loop = split_commands(datash, input);

			/* Increment the command counter */
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

