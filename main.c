#include <stdio.h>
#include <stdlib.h>

void enterElemsWithPrint(int *count);

void my_ngram(int argc, char **argv)
{
    int count[128] = {0};
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            unsigned char index = argv[i][j];
            count[index]++;
        }
    }
    enterElemsWithPrint(count);
}

void enterElemsWithPrint(int *count)
{
    for (int i = 0; i < 128; i++)
    {
        if (count[i] > 0)
        {
            printf("%c:%d\n", i, count[i]);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("%s text [text2, text3]\n", argv[0]);
        return 1;
    }

    my_ngram(argc, argv);

    return 0;
}
