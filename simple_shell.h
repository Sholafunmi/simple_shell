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
char* custom_strcat(char* destination, const char* source);
int custom_strcmp(const char* str1, const char* str2);
int custom_fgetc(FILE* stream);
char* custom_strdup(const char* source);
#endif
