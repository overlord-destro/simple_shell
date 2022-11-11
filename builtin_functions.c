#include "shell.h"


/**
*builtin_checker - checks if command is a shell builtin
*@cmd: array of command strings
*@b: linebuffer
*Return: 1 on succes
*/
int builtin_checker(char **cmd, char *b)
{
	char *builtin1 = "env";
	char *builtin2 = "exit";

	if (_strcmp(*cmd, builtin1) == 0)
	{
		env_builtin();
		return (1);
	}
	else if (_strcmp(*cmd, builtin2) == 0)
	{
		logout(cmd, b)
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

	while (env[i])
	{
		write(STDOUT_FILENO, (const void *) env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		idx++;
	}
}