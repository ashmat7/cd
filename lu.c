#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 80

bool isInteger(char *str)
{
    int i, len = strlen(str);
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
        {
            return (false);
        }
    }
    return (true);
}

int countbit2(unsigned int n)
{
    int bits = 0, i = 0;
    while (n != 0)
    {
        if (n & 1)
            bits++;
        if (n & 2)
            bits++;
        if (n & 4)
            bits++;
        if (n & 8)
            bits++;
        n >>= 4;
        i++;
    }
    printf("Number of iterations  %d \n", i);
    return bits;
}

void main()
{
    int x;
    char *path;
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_count = 0;
    FILE *fil = fopen("loop_op.txt", "a+");
    FILE *file = fopen("loop.txt", "r");
    char loop[1000];
    int loopcnt = 0, flag = 1,linecnt=0;

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        char *token = strtok(line, " ");
        while (token != NULL && loopcnt == 0)
        {
            //printf("%s\n", token); //printing each token
            if (isInteger(token))
            {
                loopcnt = *token - 48;
            }
            token = strtok(NULL, " ");
        }
        if (loopcnt != 0)
        {
            x = countbit2(loopcnt);
            printf("\nLoop UnRoll:  Count of 1's  :  %d", x);
            char str[100],str2[100];
            sprintf(str, "for(int i=0;i<%d;i+=%d){\n", loopcnt, x);
            fputs(str, fil);

            while (fgets(line, MAX_LINE_LENGTH, file))
            {
                if (line != "}")
                {
                    strcat(str2,line);
                }
            }
            for(int i=0;i<x;i++){
                fputs(str2,fil);
            }
            fputs("\n}",fil);

        }else{
            continue;
        }
    }
}