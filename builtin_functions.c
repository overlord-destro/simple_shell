#include "shell.h"


/**
*builtin_checker - checks if command is a shell builtin
*@cmd: array of command strings
*@b: linebuffer
*Return: 1 on succes
*/
int builtin_checker(char **cmd, char *b)
{
	char *env = "env";
	char *exit = "exit";

	if (_strcmp(*cmd, env) == 0)
	{
		env_builtin();
		return (1);
	}
	else if (_strcmp(*cmd, exit) == 0)
	{
		logout(cmd, b);
		return (1);
	}
	else
		return (0);
}

/**
*logout - exits shell
*@cmd: array of command strings
*@b: line buufer
*/
void logout(char **cmd, char *b)
{
	free(b);
	free_command(cmd);
	exit(0);
}

/**
*env_builtin - prints environment
*/
void env_builtin(void)
{
	int idx = 0;
	char **env = environ;

	while (env[idx])
	{
		write(STDOUT_FILENO, (const void *) env[idx], _strlen(env[idx]));
		write(STDOUT_FILENO, "\n", 1);
		idx++;
	}
}
