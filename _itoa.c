#include "holberton.h"

char *_itoa(int num, char *str)
{
        int i = 0;
        int rem = 0;
        int begin = 0;
        char *r;
        int end = 0;

        if (num == 0)
        {
                str[i] = '0';
                str[i + 1] = '\0';
                return (str);
        }

        while (num != 0)
        {
                rem = num % 10;
                str[i] = (rem > 9)? (rem-10) + 'a' : rem + '0';
                num = num / 10;
                i++;
        }
        i++;
        str[i] = '\0';
        r = malloc(sizeof(char) * (i + 1));
        end = i - 1;
        for(begin = 0; begin < i; begin++)
        {
                r[begin] = str[end];
                end--;
        }
        r[begin] = '\0';
        return (r);
}

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



char * seterror(char *cmd, int count)
{
        char *i = malloc(sizeof(char) * 10);
        char s1[100] = "sh: ";
        char *s = NULL;

        _itoa(count, i);
        s = malloc(sizeof(char) * 100);
        s = strcat(s1, i);
        s =strcat(s, ": ");
        s =strcat(s, cmd);
        s = strcat(s,": not found\n");
        free(i);
        return (s);
}
