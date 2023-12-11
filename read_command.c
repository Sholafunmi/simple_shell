#include "simple_shell.h"


void read_command(char cmd[], char *par[])
{
        char line[1024];
        int count = 0, i = 0, j = 0;
        char *array[100], *pch;

        for ( ;; )
        {
                int c  = custom_fgetc(stdin);
                line[count++] = (char) c;
                if(c == '\n')
                {
                        break;
                }
        }
        if (count == 1) return;
        pch = strtok(line, " \n");

        while (pch != NULL)
        {
                array[i++] = custom_strdup(pch);
                pch = strtok(NULL, " \n");
        }
        strcpy(cmd, array[0]);

        for (int j = 0; j < i; j++)
                par[j] = array[j];
        par[i] = NULL;
}
