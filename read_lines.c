#include "main.h"

/**
 * read_line - Reads the input string from the standard input.
 *
 * @i_eof: Pointer to store the return value of the getline function.
 *
 * Return: A pointer to the input string.
 */
char *read_line(int *i_eof)
{
	char *input = NULL; /* Pointer to store the input string */
	size_t bufsize = 0; /* Variable to store the initial buffer size */

	/* Read a line of input from the standard input using getline */
	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}

