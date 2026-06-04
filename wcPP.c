#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]); // User error message, should be updated
        return 1;                                           // Should be replaced with error
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

    while ((c = fgetc(fp)) != EOF)
    {
        if (strcmp(flag, "-c") == 0)
        {
            count++;
        }
        else if (strcmp(flag, "-l") == 0)
        {
            if (c == '\n')
            {
                count++;
            }
        }
    }

    fclose(fp);
    printf("%d %s\n", count, argv[2]);
    return 0;
}
