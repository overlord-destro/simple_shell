#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

/*string_handling functions*/
int _strlen(char *str);
char *check_str(char *str, int ch);
int _strcmp(char *str, char *str1);
int _strncmp(char *str, char *str1, size_t n);
char *_strdup(char *str);

/*command_handlers*/
char **tokenizer(char *str);
void exec_cmd(char *c, char **cmd);
void free_command(char **cmd);
void cmd_type(char **cmd, char *c);
char *_getpath(void);
char *append_path(char *path, char *cmd);
char *search_path(char **p, char *cmd);


/*builtin*/
int builtin_checker(char **cmd, char *b);
void logout(char **cmd, char *b);
void env_builtin(void);
void print_prompt(void);
void handle_sig(int n);

extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern char **environ;

/**
*struct info - Status
*@final_exit: First member
*@ln_count: Second member
* Description: Used in error handling
*/
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
* struct flags - Holds flags
* @interactive: First member
* Description: used to handle
* boolean switches
*/
struct flags
{
	bool interactive;
} flags;



#endif /* SHELL_H */
