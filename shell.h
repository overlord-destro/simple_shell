#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*string_handling functions*/
int _strlen(char *str);
char *check_str(char *str, int ch);
int _strcmp(char *str, char *str1);
int _strncmp(char *str, char *str1, size_t n);
char _strdup(char *str);


#endif /* SHELL_H */
