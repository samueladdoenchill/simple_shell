#include "main.h"

/**
 * free_data - Frees data structure.
 *
 * @datash: Pointer to data_shell data structure.
 * Return: No return value.
 *
 * This function frees memory used by data_shell data structure pointed
 * to by @datash. It releases memory used by _environ array and its
 * elements, as well as pid string. Make sure to call this function when
 * data structure is no longer needed to avoid memory leaks.
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - Initializes data structure.
 *
 * @datash: Pointer to data_shell data structure.
 * @av: Argument vector (array of strings).
 * Return: No return value.
 *
 * This function initializes data_shell data structure pointed to by @datash.
 * It sets initial values of its members, including av, input, args, status,
 * counter, _environ, and pid. The _environ array is initialized with copy of
 * current environment variables. The pid member is set to the process ID of
 * current shell process (represented as a string). Make sure to call this
 * function before using data_shell data structure to ensure proper
 * initialization.
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry point of shell program.
 *
 * @ac: Argument count (number of command-line arguments).
 * @av: Argument vector (array of strings representing command-line arguments).
 *
 * Return: The exit status of shell program (0 on success, 255 on error).
 *
 * This function is main entry point of shell program. It sets up
 * data_shell data structure, installs signal handler for SIGINT (Ctrl+C),
 * enters shell loop using shell_loop() function, and then frees
 * data structure using free_data() before exiting. The exit status of shell
 * program returned, which set in data_shell data structure as datash.status.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}

