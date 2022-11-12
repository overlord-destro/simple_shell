#include "shell.h"

/**
*tokenizer - splits strings into tokens using strtok
*@str: string to be split
*Return: returns a pointer to an array of the tokenized strings
*/
char **tokenizer(char *str)
{
	size_t idx, i = 0;
	int t = 1;
	char **tokens;
	char *buff, *token, *buffptr;
	char *delimiters = " :\t\r\n";

	buff = _strdup(str);
	if (buff == NULL)
		return (NULL);

	buffptr = buff;

	while (*buffptr)
	{
		if (check_str(delimiters, *buffptr) != NULL && i == 0)
		{
			t++;
			i = 1;
		}
		else if (check_str(delimiters, *buffptr) == NULL && i == 1)
			i = 0;
		buffptr++;
	}
	tokens = malloc(sizeof(char *) * (t + 1));
	token = strtok(buff, delimiters);
	while (token != NULL)
	{
		tokens[idx] = _strdup(token);
		if (tokens[idx] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delimiters);
		idx++;
	}
	tokens[idx] = NULL;
	free(buff);
	return (tokens);
}

/**
*exec_cmd - executrs command
*@c: command
*@cmd: array of strings of commands
*/
void exec_cmd(char *c, char **cmd)
{
	pid_t newp;
	int status;
	char **envp = environ;

	newp = fork();
	if (newp < 0)
		perror(c);
	if (newp == 0)
	{
		execve(c, cmd, envp);
		perror(c);
		free(c);
		free_command(cmd);
		exit(98);
	}
	else
		wait(&status);
}

/**
*free_command - frees array of commands
*@cmd: array of commands
*/
void free_command(char **cmd)
{
	int idx = 0;

	if (cmd == NULL)
		return;

	while (cmd != NULL)
	{
		free(cmd[idx]);
		idx++;
	}
	free(cmd);
}
