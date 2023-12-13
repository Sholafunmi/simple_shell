#include "simple_shell.h"


/**
 * type_prompt - Display a shell prompt.
 * This function prints a shell prompt to the standard output.
 * If it's the first time calling the function, it clears the screen.
 * The prompt displayed is a simple "$".
 *
 * It uses ANSI escape codes to clear the screen on the first invocation.
 * The function does not take any parameters.
 *
 * Return: void
 */

void type_prompt(void)
{
	static int first_time = 1;

	if (first_time)

	{
		const char *CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";

		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	printing("$");
	//printf("$");
}
