#include "main.h"

/**
 * aux_help_env - Provides help information for built-in 'env' command.
 * Return: No return value.
 *
 * This function displays information about 'env' built-in command.
 * It explains how to print environment of the shell.
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_setenv - Provides help information for built-in 'setenv' command.
 * Return: No return value.
 *
 * This function displays information about 'setenv' built-in command.
 * It explains how to add new definition to environment.
 */
void aux_help_setenv(void)
{
	char *help = "setenv: setenv (const char *name, const char *value)";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add a new definition to the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_unsetenv - Provides information for built-in 'unsetenv' command.
 * Return: No return value.
 *
 * This function displays information about 'unsetenv' built-in command.
 * It explains how to remove entry completely from environment.
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_general - Entry point for general information for 'help' built-in.
 * Return: No return value.
 *
 * This function displays general help information for 'help' built-in command.
 * It lists available built-in commands in shell and provides instructions
 * on how to use 'help' command to get more information about specific command.
 */
void aux_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally. Type 'help' to see the list.";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\nsetenv: setenv [variable] [value]\nunsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_exit - Help information for built-in 'exit' command.
 * Return: No return value.
 *
 * This function displays information about 'exit' built-in command.
 * It explains how to exit shell and provides information about exit status.
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. If N is omitted, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "status is that of the last command executed.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

