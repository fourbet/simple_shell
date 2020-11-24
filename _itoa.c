#include "holberton.h"

/**
 * _itoa - convert integer to string
 *
 * @num : interger to converted
 * @str: string to converted
 *
 * Return: new string containing the integer num
 */
char *_itoa(int num, char *str)
{
	int i = 0;
	int rem = 0;
	int begin = 0;
	char *r = NULL;
	int end = 0;

	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	while (num)
	{
		rem = num % 10;
		if (rem >= 10)
			str[i] = ('a' + (rem - 10));
		else
			str[i] = ('0' + rem);
		num = num / 10;
		i++;
	}
	i++;
	str[i] = '\0';
	r = malloc(sizeof(char) * (i));
	i--;
	end = i - 1;
	for (begin = 0; begin < i; begin++)
	{
		r[begin] = str[end];
		end--;
	}
	r[begin] = '\0';
	return (r);
}
/**
 * _atoi - convert string to integer
 *
 * @str: string to converted
 *
 * Return: int converted
 */
int _atoi(char *str)
{
	int sign = 1;
	int i = 0;
	int res = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
		res = res * 10 + str[i] - '0';
	res *= sign;
	return (res);
}
/**
 * seterror - set message error
 *
 * @cmd: string containing the command
 * @count: number of interration in the main in the main loop
 *
 * Return: new string
 */
char *seterror(char *cmd, int count)
{
	char *i = NULL;
	char s1[100] = "sh: ";
	char *s = NULL;

	i = malloc(sizeof(char) * ((count / 10) + 1));
	i = _itoa(count, i);
	s = malloc(sizeof(char) * 100);
	s = _strcat(s1, i);
	s = _strcat(s, ": ");
	s = _strcat(s, cmd);
	s = _strcat(s, ": not found\n");
	free(i);
	return (s);
}
