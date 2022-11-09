#include "shell.h"


/**
*_strlen - finds length of string
*@str: string to be checked
*Return: returns length of strength
*/
int _strlen(char *str)
{
	int i = 0;

	while (*str)
	{
		i++;
		str++
	}
	return (i);
}

/**
*check_str - checks a string for character
*@str: string to be checked
*@ch: character we are searching for
*Return: returns instance of character
*/
char *check_str(char *str, int ch)
{
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
}

/**
*_strcmp - compares 2 strings
*@str: fisrt string
*@str1: second string
*Return: difference
*/
int _strcmp(char *str, char *str1)
{
	int diff;

	if (str == NULL || str1 == NULL)
		return (0);

	while (*str && *str1)
	{
		diff = *str - str1;
		if (diff != 0)
			break;
		str++;
		str1++;
	}
	return (diff);
}
/**
*_strncmp - compares strings up to a certain number of bites
*@str: first string
*@str1: second string
*@n: number of bytes
*Return: diff
*/

int _strncmp(char *str, char *str1, size_t n)
{
	size_t i = 0;
	int diff;

	while (*str && *str1 && i < n)
	{
		diff = *str - *str1;
		if (diff != 0)
			break;
		str++;
		str1++;
	}
	return (diff);
}
/**
*_strdup - replicates string
*@str: string to be replicated
*Return: pointer to replicant, haha
*/
char _strdup(char *str)
{
	char *rep;
	int i = 0;

	if (str == NULL)
		return (NULL);

	rep = malloc(sizeof(char) * (_strlen(str) + 1));
	if (rep == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		rep[i] = str[i]
		i++;
	}
	rep[i] = '\0';
}
