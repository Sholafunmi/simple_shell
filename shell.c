#include "shell.h"

void shell_loop(void)
{
    char *line;
    char **args;
    int status;

    do
    {
        printf("$");
        line = read_line();
        args = split_line(line);
        status = execute_command(args);

        free(line);
        free(args);

    } while (status);
}

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    line[strcspn(line, "\n")] = '\0';

    return line;
}

char **split_line(char *line)
{
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    char *token;
    int i = 0;

    token = strtok(line, " ");
    while (token != NULL)
    {
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **args)
{
    pid_t pid, wpid;
    int status;

    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1] == NULL)
            fprintf(stderr, "SimpleShell: expected argument to \"cd\"\n");
        else
        {
            if (chdir(args[1]) != 0)
                perror("SimpleShell");
        }
    }
    else if (strcmp(args[0], "ls") == 0)
    {
        pid = fork();
        if (pid == 0)
        {
            execvp(args[0], args);
            perror("SimpleShell");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            perror("SimpleShell");
        }
        else
        {
            do
            {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    else if (strcmp(args[0], "mkdir") == 0)
    {
        pid = fork();
        if (pid == 0)
        {
            execvp(args[0], args);
            perror("SimpleShell");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            perror("SimpleShell");
        }
        else
        {
            do
            {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    else if (strcmp(args[0], "env") == 0)
    {
        char **env = environ;
        while (*env)
        {
            printf("%s\n", *env);
            env++;
        }
    }
    else if (strcmp(args[0], "exit") == 0)
    {
        return 0;
    }
    else
    {
        pid = fork();
        if (pid == 0)
        {
            if (execvp(args[0], args) == -1)
                perror("SimpleShell");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            perror("SimpleShell");
        }
        else
        {
            do
            {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    return 1;
}

