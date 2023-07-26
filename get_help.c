#include "main.h"

/**
 * get_help - Retrieves help messages based on given builtin command.
 *
 * @datash: Data structure containing arguments and input.
 * Return: Always returns 1.
 */
int get_help(data_shell *datash)
{
	/* Check if no specific builtin command is provided */
	if (datash->args[1] == 0)
		aux_help_general();
	/* Check for each specific builtin command and display corresponding help */
	else if (_strcmp(datash->args[1], "setenv") == 0)
		aux_help_setenv();
	else if (_strcmp(datash->args[1], "env") == 0)
		aux_help_env();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		aux_help_unsetenv();
	else if (_strcmp(datash->args[1], "help") == 0)
		aux_help();
	else if (_strcmp(datash->args[1], "exit") == 0)
		aux_help_exit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		aux_help_cd();
	else if (_strcmp(datash->args[1], "alias") == 0)
		aux_help_alias();
	/* Display error message if specified command doesn't have help */
	else
		write(STDERR_FILENO, datash->args[0],
				_strlen(datash->args[0]));

	/* Set the status to 0 to indicate success */
	datash->status = 0;
	return (1);
}

