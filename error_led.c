#include "shell.h"

/**
 * error_126 - Creates an error message 
 * @ac: An array of arguments passed to the command.
 * Return: error string
 */
char *error_126(char **ac)
{

	
	char *error, *err_str, *name;
	int len, err;

	err_str = _itoa(err);
	
	if (err_str == NULL)
		return (NULL);

	len = _strlen(name) + _strlen(err_str) + _strlen(ac[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(err_str);
		return (NULL);
}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, err_str);
	_strcat(error, ": ");
	_strcat(error, ac[0]);
	_strcat(error, ": Permission denied\n");

free(err_str);
return (error);
}

/**
 * error_127 - Creates an error message for command not found failures.
 * @ac: An array of arguments passed to the command.
 * Return: The error string.
 */
char *error_127(char **ac)
{
	char *error, *hist_str, *name;
	int len, hist;

	hist_str = _itoa(hist);
	if (hist_str == NULL)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(ac[0]) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, ac[0]);
	_strcat(error, ": not found\n");

	free(hist_str);
	return (error);
}

