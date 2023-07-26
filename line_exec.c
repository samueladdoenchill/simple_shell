#include "main.h"

/**
 * exec_line - Finds built-ins and commands and executes them.
 *
 * @datash: Data structure containing relevant arguments and information.
 * Return: 1 on success.
 *
 * This function is responsible for executing built-in commands and other
 * external commands provided by user. It first checks if given command
 * is built-in command by using get_builtin() function. If it is built-in
 * command, it calls corresponding built-in function and returns its result.
 * If it is not built-in command, it is assumed to be external command, and
 * the cmd_exec() function is called to execute it.
 *
 * The @datash argument is pointer to data_shell structure, which contains
 * relevant information and arguments needed for executing command.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	/* Check if given command is built-in command */
	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	/* If not built-in command, assume it's external command and execute it */
	return (cmd_exec(datash));
}

