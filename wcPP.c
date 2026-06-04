#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]); // User error message
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("fopen"); // System error message
        return 1;
    }
    int count = 0;

    fclose(fp);
    return 0;
}
