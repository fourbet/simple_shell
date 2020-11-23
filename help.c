#include "holberton.h"



int built_in_help(char **cmd)
{
        int i = 0;
        char *builtin_name[] = {"env","exit","setenv","unsetenv","cd","help",NULL};
        char *builtin_info[] = {"Prints the current environnement\n",
                                "Exits the shell\n",
                                "Initialize a new environnement variable or modify existing one\n",
                                "Remove an environnement variable\nFormat: unsetenv VARIABLE\n",
                                "Changes the current directory of the process\nFormat: cd DIRECTORY\n",
                                "Gives information about builtins\n Format: help BUILTIN\n",
                                NULL
        };

        while (cmd[i] != NULL)
                i++;

        if (i != 2)
        {
                write(STDERR_FILENO,"Failure\n",8);
                return (1);
        }
        i = 0;
        while (builtin_name[i] != NULL)
        {
                if (_strncmp(cmd[1], builtin_name[i], _strlen(builtin_name[i])) == 0)
                {
                        write(STDOUT_FILENO,builtin_info[i],_strlen(builtin_info[i]));
                        return (1);
                }
                i++;
        }
        write(STDERR_FILENO,"Failure\n",8);
        return (1);
}
