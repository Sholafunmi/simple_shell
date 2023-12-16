#include "shell.h"

/**
 * signal_control - starts shell all over upon a signal.
 * @sig: signal.
 */

void signal_control(int sig)
{
	char *shell = "\n#cisfun$ ";

	(void)sig;
	signal(SIGINT, signal_control);
	write(0, shell, 3);
}

/**
 * execute - Executes a command in a child process.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - a corresponding error code.
 *         O/w - The exit value of the last executed command.
 */

int exec_cmd(char **ac, char **point)
{
	pid_t pid;
	int ppid, flag = 0, back = 0;
	char *cmd = ac[0];

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		flag = 1;
		cmd = get_location(cmd);
	}

	if (cmd == NULL || (access(cmd,  F_OK) == -1))
	{
		if (errno == EACCES)
			back = (create_error(ac, 126));
		else
			back = (create_error(ac, 127));
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			if (flag)
				free(cmd);
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			execve(cmd, ac, environ);
			if (errno == EACCES)
				back = (create_error(ac, 126));
			free_env();
			free_args(ac, point);
			free_alias_list(aliases);
			_exit(back);
		}
		else
		{
			wait(&ppid);
			back = WEXITSTATUS(ppid);
		}
	}
	if (flag)
		free(cmd);
	return (back);
}
