#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: wcPP -c|-l|-w <filename>\n"); // User error message, should be updated
        return 1;                                             // Should be replaced with error
    }
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL)
    {
        perror("fopen"); // System error message
        return 1;
    }
    char *flag = argv[1];
    int count = 0;
    int c;
    int in_word = 0;

    if (strcmp(flag, "-c") == 0)
    {
        while ((c = fgetc(fp)) != EOF)
        {
            count++;
        }
    }
    else if (strcmp(flag, "-l") == 0)
    {
        while ((c = fgetc(fp)) != EOF)
        {
            if (c == '\n')
            {
                count++;
            }
        }
    }
    else if (strcmp(flag, "-w") == 0)
    {
        while ((c = fgetc(fp)) != EOF)
        {
            if (isspace((unsigned char)c))
            {
                in_word = 0;
            }
            else
            {
                if (in_word == 0)
                {
                    count++;
                    in_word = 1;
                }
            }
        }
    }
    fclose(fp);
    printf("%d %s\n", count, argv[2]);
    return 0;
}
