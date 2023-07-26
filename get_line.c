#include "main.h"

/**
 * bring_line - Assigns the lineptr variable for get_line.
 * @lineptr: Buffer that stores the input string.
 * @n: Size of lineptr.
 * @buffer: String that is being called to lineptr.
 * @j: Size of buffer.
 *
 * This function is responsible for managing the memory allocated for lineptr
 * and ensuring it has enough space to hold the input string.
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		/* If lineptr is NULL, assign buffer to it and set n accordingly. */
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		/* If lineptr already has buffer, check if it has enough space for input. */
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		/* If lineptr has enough space, copy the buffer to it and free the buffer. */
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * get_line - Reads input from a stream.
 * @lineptr: Buffer that stores the input.
 * @n: Size of lineptr.
 * @stream: Stream to read from (stdin in this case).
 * Return: The number of bytes read.
 *
 * This function reads input from the given stream and stores it in lineptr.
 * It allocates memory for buffer to store input and resizes if needed.
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);

	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}

