#include "shell.h"

/**
 * main - Entry to shell
 * @argc: Number of arguments
 * @argv: Argument vector
 * @envp: Environment variable
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char *envp[])
{
	char *lineptr = NULL, *pathcmd = NULL, *path = NULL;
	size_t buffer_size = 0;
	ssize_t num_chars_read = 0;
	char **cmd = NULL, **paths = NULL;
	(void) envp, (void) argv;

	if (argc < 1)
		return (-1);
	signal(SIGINT, handle_sig);
	while (1)
	{
		free_command(cmd);
		free_command(paths);
		free(pathcmd);
		print_prompt();
		num_chars_read = getline(&lineptr, &buffer_size, stdin);
		if (num_chars_read < 0)
			break;
		info.ln_count++;
		if (lineptr[num_chars_read - 1] == '\n')
			lineptr[num_chars_read - 1]  = '\0';
		cmd = tokenizer(lineptr);
		if (cmd == NULL || *cmd == NULL || **cmd == '\0')
			continue;
		if (cmd_type(cmd, lineptr))
			continue;
		path = _getpath();
		paths = tokenizer(path);
		pathcmd = search_path(paths, cmd[0]);
		if (pathcmd == NULL)
			perror(argv[0]);
		else
			exec_cmd(pathcmd, cmd);
	}
	if (num_chars_read < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(lineptr);
	return (0);
}

/**
 * print_prompt - Prints prompt
 * When shell is in interactive mode
 *
 * Return: Void
 */
void print_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "> ", 2);
}

/**
 * handle_sig - Allows ctrl+C to be printed by the shell
 * @n: signum
 *
 * Return: void
 */
void handle_sig(int n __attribute__((unused)))
{
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "> ", 2);
}


/**
 * cmd_type - Checks whether command is builtin or executable
 * @cmd: Pointers to command arguments
 * @c: Line pointer returned by getline function
 *
 * Return: 1- command executable, 0- otherwise
 */
int cmd_type(char **cmd, char *c)
{
	if (builtin_checker(cmd, c))
	{
		return (1);
	}
	else if (**cmd == '/')
	{
		exec_cmd(cmd[0], cmd);
		return (1);
	}
	return (0);
}
