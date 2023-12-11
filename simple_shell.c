#include "simple_shell.h"


int main()
{
        char cmd[100], command[100], *parameters[20];

        char *envp[] = { (char*) "PATH=/bin", 0};
        while(1)
        {
                type_prompt();
                read_command(command, parameters);
                if (fork() != 0) {
                        wait(NULL);
                } else {
                        custom_strcpy(cmd, "/bin/");
			custom_strcat(cmd, command);
                 	execve(cmd, parameters, envp);
                }
		if (custom_strcmp(command, "exit") == 0) 
		{
                        break;
                }
        }
        return 0;
}
