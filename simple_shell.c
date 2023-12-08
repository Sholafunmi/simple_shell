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
                        strcat(cmd, command); // substitute
                        execve(cmd, parameters, envp);
                }
                if (strcmp(command, "exit") == 0) {  // substitute strcmp()
                        break;
                }
        }
        return 0;
}
