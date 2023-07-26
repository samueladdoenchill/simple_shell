#include "main.h"

/**
 * aux_help - Provides help information for built-in 'help' command.
 * Return: No return value.
 *
 * This function displays information about built-in commands.
 * It shows brief summaries of built-in commands available in shell.
 */
void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about built-in commands.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of built-in commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_alias - Provides help information for built-in 'alias' command.
 * Return: No return value.
 *
 * This function displays information about 'alias' built-in command.
 * It explains how to define or display aliases in shell.
 */
void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_cd - Provides help information for built-in 'cd' command.
 * Return: No return value.
 *
 * This function displays information about 'cd' built-in command.
 * It explains how to change shell's working directory.
 */
void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

