#include "main.h"

/**
 * exit_shell - Exits the shell.
 *
 * @datash: Data relevant to the shell (status and args).
 *
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;   /* Stores unsigned integer status */
	int is_digit;           /* Flag to check if argument is a digit */
	int str_len;            /* Length of argument string */
	int big_number;         /* Flag to check if number exceeds INT_MAX */

	/* If the exit command has an argument */
	if (datash->args[1] != NULL)
	{
		/* Convert the argument to an unsigned integer */
		ustatus = _atoi(datash->args[1]);

		/* Check if the argument is a valid digit */
		is_digit = _isdigit(datash->args[1]);

		/* Get the length of the argument string */
		str_len = _strlen(datash->args[1]);

		/* Check if the number is too large for an integer */
		big_number = ustatus > (unsigned int)INT_MAX;

		/* If the argument is not a valid digit or is too large */
		if (!is_digit || str_len > 10 || big_number)
		{
			/* Display an error message and set the status to 2 */
			get_error(datash, 2);
			datash->status = 2;
			return (1); /* Return 1 to indicate an error occurred */
		}

		/* Set the shell's status to the lower 8 bits of the ustatus */
		datash->status = (ustatus % 256);
	}

	/* Return 0 to indicate successful exit from the shell */
	return (0);
}

