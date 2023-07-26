#include "main.h"

/**
 * get_sigint - Handles the SIGINT (ctrl + c) signal in the prompt.
 * @sig: The signal number (ignored in this function).
 *
 * This function is signal handler for SIGINT signal, which is raised
 * when user presses ctrl + c while program is running. It writes
 * message to standard output and provides friendly prompt "^-^ ".
 */
void get_sigint(int sig)
{
	/* Avoid unused parameter warning */
	(void)sig;

	/* Write newline and friendly prompt to standard output */
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

