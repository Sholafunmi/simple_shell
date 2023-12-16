#include "shell.h"

/**
 * co - function that returns error
 * @filepath: file path
 * Return: integer
 */

int co(char *filepath)
{
	char *err, *lerr_str, *name;
	int length, lerr;

	lerr_str = _itoa(lerr);
	if (lerr_str == NULL)
		return (1);

	length = _strlen(name) + _strlen(lerr_str) + _strlen(filepath) + 16;
	err = malloc(sizeof(char) * (length + 1));
	if (err == NULL)
{
	free(lerr_str);
	return (1);
}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, lerr_str);
	_strcat(err, ": Can not open ");
	_strcat(err, filepath);
	_strcat(err, "\n");

	free(lerr_str);
	write(STDERR_FILENO, err, length);
	free(err);
	return (1);
}

/**
 * take_file- Take file
 * @filepath: file path.
 * @exe: second parameter
 * Return: returns an integer
 */

int take_file(char *filepath, int *exe)
{
	ssize_t file, _read, i;
	unsigned int linesize = 0;
	unsigned int oldsize = 200;
	char *line, **args, **front;
	char store[200];
	int back, lerr;

	lerr = 0;
	file = open(filepath, O_RDONLY);
	if (file == -1)
	{
		*exe = co(filepath);
		return (*exe);
	}
	line = malloc(sizeof(char) * oldsize);
	if (line == NULL)
		return (-1);
	do {
		_read = read(file, store, 200);
		if (_read == 0 && linesize == 0)
			return (*exe);
		store[_read] = '\0';
		linesize += _read;
		line = _realloc(line, oldsize, linesize);
		_strcat(line, store);
		oldsize = linesize;
	}
       	while (_read);
	for (i = 0; line[i] == '\n'; i++)
		line[i] = ' ';
	for (; i < linesize; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = ';';
			for (i += 1; i < linesize && line[i] == '\n'; i++)
				line[i] = ' ';
		}
	}
	
	variable_replacement(&line, exe);
	handle_line(&line, linesize);
	args = _strtok(line, " ");
	free(line);
	if (args = 0) 
		return (0);
	if (check_args(args) != 0)
	{
		*exe = 2;
		free_args(args, args);
		return (*exe);
	}
	front = args;

	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			back = call_args(args, front, exe);
			args = &args[++i];
			i = 0;
		}
	}

	back = call_args(args, front, exe);

	free(front);
	return (back);
}

