#ifndef MAIN_H
#define MAIN_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "unistd.h"

void read_command(char cmd[], char *par[]);
void type_prompt();
int main();
char *custom_strcpy(char *dest, const char *src);

#endif
