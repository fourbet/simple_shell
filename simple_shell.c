#include "holberton.h"
/*
char *itoa(int num, char *str)
{
	int i = 0;
	int rem = 0;
	int begin = 0;
	char *r;
	int end = 0;

	puts("a\n");
	if (num == 0) 
	{ 
		str[i] = '0'; 
		str[i + 1] = '\0';
		printf("str :%s\n", str);
		return (str); 
	} 

	while (num != 0) 
	{
		puts("h\n");
		rem = num % 2;
		str[i] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
		num = num / 2;
		i++;
	} 
	i++;
	str[i] = '\0';
	printf("str1 :%s\n", str);
	r = malloc(sizeof(char) * (i + 1));
	end = i - 1;
	for(begin = 0; begin < i; begin++)
	{
		r[begin] = str[end];
		end--;
	}
	r[begin] = '\0';
	puts("OK2\n");
	return (r);
}

char * seterror(char *cmd, int count)
{
	char *s = NULL;
	char *i = malloc(sizeof(char) * 10);
	char *s1 = "sh ";

	puts("OK1\n");
	itoa(count, i);
	s = malloc(sizeof(char) * ( 7 + _strlen(cmd)));
	puts("before strcat\n");
	printf("i :%s\n", i);
	s = strcat(s1, _strdup(i));
	printf("s : %s\n", s);
	return (s);
}
*/		   

int main(int ac, char **av, char **env)
{
	char **cmd = NULL;
	char *path = NULL;
	char *buffer = NULL;
	size_t bufsize = 0;
	int i = 0;
	int built = 0;
	list_t *ptrEnv = NULL;
	char *serror = NULL;
	ptrEnv = getenvLinked(env);

	type_prompt(ptrEnv);
	while (1 && (getline(&buffer, &bufsize, stdin) != EOF))
	{
		
		if (_strcmp(&buffer[0],"\n") != 0)
		{
			path = NULL;
			cmd = NULL;
			cmd = split(buffer);
			if (cmd == NULL)
			{
				perror("error split");
				return (-1);
			}
			built = exec_builtin(cmd, &ptrEnv);

			if (built == 0)
				return (0);

			if (built != 1)
				path = get_path(cmd, ptrEnv);

			if (path == NULL && built != 1)
			{
				//serror = seterror(cmd[0], i);
				perror("command :");
				/*	while (cmd[i])
				{
					write(1, cmd[i], _strlen(cmd[i]));
					putchar(' ');
					i++;
				}
				write(1, ": command not found", 20);
				putchar('\n');*/
			}

			if (path != NULL)
			{
				if (exec_cmd(cmd, path) == -1)
				{
					perror("error exec cmd");
					return (-1);
				}
			}
		}
		if (isatty(STDIN_FILENO))
		{
			free(path);
			free_array(cmd);
		}
		i++;
		type_prompt(ptrEnv);
	}
	free(path);
	free(buffer);
	free_array(cmd);
	(void)ac;
	(void)av;
	return (0);
}
